//
// Created by Andrea Lipperi on 14/11/22.
//

#include "cartMethods.h"
#include "subcategories.h"
#include "database.h"
#include <SQLiteCpp/SQLiteCpp.h>
#include <SQLiteCpp/Statement.h>
#include <SQLiteCpp/Database.h>
#include <iostream>
#include <string>
using namespace std;

TableCart::TableCart() {
    string query="CREATE TABLE IF NOT EXISTS cart (id INTEGER PRIMARY KEY autoincrement, quantity INT NOT NULL, id_store INT NOT NULL, id_user INT NOT NULL, id_prov, FOREIGN KEY (id_user) REFERENCES users (id),FOREIGN KEY (id_prov) REFERENCES users (id), FOREIGN KEY (id_store) REFERENCES store (id));";
    db.exec(query);
}
void TableCart::add(const Cart& cart) {
    data=cart;
    string query_user="SELECT id FROM users WHERE username='"+data.get_id_user()+"'";
    int id_user=db.execAndGet(query_user);
    string query_prov="SELECT id FROM users WHERE username='"+data.get_id_prov()+"'";
    int id_prov=db.execAndGet(query_prov);
    int id=std::stoi(data.get_id_store());

    string query_insert="INSERT INTO cart (quantity, id_store,id_user, id_prov) VALUES (" + to_string(data.get_quantity()) + ", " + to_string(id) + ","+
                                                                                                                                                    to_string(id_user)+","+to_string(id_prov)+"";

    db.exec(query_insert);
}
void TableCart::remove_all(const string &username) {

    string query_select="SELECT id FROM users WHERE username ='"+ username+"'";
    int id = db.execAndGet(query_select).getInt();
    string query="DELETE FROM cart WHERE id_user = "+ to_string(id)+"";
    db.exec(query);
}
void TableCart::remove_prod(int id) {

    string query="DELETE FROM cart WHERE id = "+ to_string(id)+"";
    db.exec(query);
}
void TableCart::changeData(const string& IDuser, Store &prod, const string &new_IDprov, const int &new_quantity) {
    int num_result = 0;
    int i=0;
    SQLite::Statement query_select(db, "SELECT * FROM store");
    while (query_select.executeStep()){
        if (query_select.getColumn(1).getText() == prod.get_desc()) {
            num_result++;
        } else {
            i++;
        }
    }
    query_select.reset();
    if (num_result>0) {
        string query="UPDATE cart SET quantity = "+ to_string(new_quantity)+", id_prov='"+new_IDprov+"' WHERE id = '"+ IDuser+"' AND id_prod = "+
                                                                                                                              to_string(i)+";";
        db.exec(query);
    }
}

int TableCart::select_count(const string &username) {
    string query="SELECT id FROM users WHERE username ='"+ username+"'";
    int id = db.execAndGet(query).getInt();
    string query_select_count="SELECT count(*) FROM cart WHERE id_user ="+ to_string(id)+"";
    int count = db.execAndGet(query_select_count).getInt();
    return count;
}

string** TableCart::select(const string &username) {


    string query_user="SELECT id FROM users WHERE username ='"+ username+"'";
    int id = db.execAndGet(query_user).getInt();

    string** mat=new string *[select_count(username)];
    for (int k = 0; k < select_count(username); k++) {
        mat[k] = new string[6];
    }
    string select;
    select="SELECT desc_prod, price_product, username, quantity, store.id,cart.id FROM users,cart,store WHERE id_store=store.id AND store.id_prov=users.id AND id_user="+to_string(id) +" ORDER BY username;";

    SQLite::Statement query(db,select);
    int m=0;
    int n=0;
    while (query.executeStep()){
        while (n<6) {
            mat[m][n]=query.getColumn(n).getText();
            n++;
        }
        n=0;
        m++;
    }
    return mat;
}
