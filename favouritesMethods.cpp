//
// Created by Andrea Lipperi on 14/11/22.
//

#include "favouritesMethods.h"
#include "subcategories.h"
#include "database.h"
#include <SQLiteCpp/SQLiteCpp.h>
#include <SQLiteCpp/Statement.h>
#include <SQLiteCpp/Database.h>
#include <iostream>
#include <string>
using namespace std;

TableFavourites::TableFavourites() {
    string query="CREATE TABLE IF NOT EXISTS favourites (id INTEGER PRIMARY KEY autoincrement, id_store INT NOT NULL, id_cust INT NOT NULL, id_prov INT NOT NULL, FOREIGN KEY (id_store) REFERENCES store(id), FOREIGN KEY (id_cust) REFERENCES users (id), FOREIGN KEY (id_prov) REFERENCES users (id));";
    db.exec(query);
}
void TableFavourites::add(const Favourites& cart) {
    data=cart;
    int k=1;
    int j=1;
    int control_prov=0;
    int control_cust=0;
    /*cout << data.get_id_cust();
    cout << data.get_id_prov()*/
    SQLite::Statement query_user(db, "SELECT * FROM users");
    while (query_user.executeStep()) {
        if (query_user.getColumn(7).getText() != data.get_id_prov() && control_prov==0) {
            k++;
        } else {
            control_prov=1;
        }
        if (query_user.getColumn(7).getText() != data.get_id_cust() && control_cust==0){
            j++;
        } else {
            control_cust=1;
        }
    }
    query_user.reset();
    int id=std::stoi(data.get_id_store());
    string query_insert="INSERT INTO favourites (id_store,id_cust, id_prov) VALUES ("+to_string(id)+", "+to_string(j)+","+to_string(k)+");";

    db.exec(query_insert);
}
void TableFavourites::remove_all(const string &IDuser) {

    string query="DELETE FROM favourites WHERE id_cust = '"+IDuser+"'";
    db.exec(query);
}
void TableFavourites::remove_prod(int id) {

    string query="DELETE FROM favourites WHERE id = "+ to_string(id)+"";
    cout << query;
    db.exec(query);
}
void TableFavourites::changeData(const string& IDuser, Subcategories &prod, const string &new_IDprov, const int &new_quantity) {
    int num_result = 0;
    int i=0;
    SQLite::Statement query_select(db, "SELECT * FROM subcategories");
    while (query_select.executeStep()){
        if (query_select.getColumn(1).getText() == prod.get_name()) {
            num_result++;
        } else {
            i++;
        }
    }
    query_select.reset();
    if (num_result>0) {
        string query="UPDATE favourites SET quantity = "+ to_string(new_quantity)+", id_prov='"+new_IDprov+"' WHERE id = '"+ IDuser+"' AND id_sub = "+
                     to_string(i)+";";
        db.exec(query);
    }
}

string** TableFavourites::select(const string &username) {


    string query_user="SELECT id FROM users WHERE username ='"+ username+"'";
    int id = db.execAndGet(query_user).getInt();

    string** mat=new string *[select_count(username)];
    for (int k = 0; k < select_count(username); k++) {
        mat[k] = new string[4];
    }
    string select;
    int n_disp;
    select="SELECT desc_prod, price_product, username, favourites.id FROM users,favourites,store WHERE favourites.id_prov=users.id AND id_store=store.id AND id_cust="+to_string(id) +" ORDER BY username;";

    SQLite::Statement query(db,select);
    int m=0;
    int n=0;
    while (query.executeStep()){
        while (n<4) {
            mat[m][n]=query.getColumn(n).getText();
            n++;
        }
        n=0;
        m++;
    }
    return mat;
}
int TableFavourites::select_count(const string &username) {
    string query="SELECT id FROM users WHERE username ='"+ username+"'";
    int id = db.execAndGet(query).getInt();
    string query_select_count="SELECT count(*) FROM favourites WHERE id_cust ="+ to_string(id)+"";
    int count = db.execAndGet(query_select_count).getInt();
    return count;
}