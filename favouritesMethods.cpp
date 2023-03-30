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
    string query="CREATE TABLE IF NOT EXISTS favourites (id INTEGER PRIMARY KEY autoincrement, id_store INT NOT NULL, id_cust INT NOT NULL, id_prov INT NOT NULL, FOREIGN KEY (id_cust) REFERENCES users (id), FOREIGN KEY (id_prov) REFERENCES users (id));";
    db.exec(query);
}
void TableFavourites::add(const Favourites& cart) {
    data=cart;
    int k=1;
    int j=1;
    SQLite::Statement query_user(db, "SELECT * FROM users");
    while (query_user.executeStep()) {
        if (query_user.getColumn(2).getText() != data.get_id_prov()) {
            k++;
        }
        if (query_user.getColumn(2).getText() != data.get_id_cust()){
            j++;
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
void TableFavourites::remove_prod(Subcategories &prod,const string &IDuser) {
    int i=1;
    int k=1;
    SQLite::Statement query_sub(db, "SELECT * FROM subcategories");
    while (query_sub.executeStep()) {
        if (query_sub.getColumn(1).getText() != prod.get_name()) {
            i++;
        }
    }
    query_sub.reset();
    SQLite::Statement query_user(db, "SELECT * FROM user");
    while (query_user.executeStep()) {
        if (query_user.getColumn(2).getText() != IDuser) {
            k++;
        }
    }
    query_user.reset();

    string query="DELETE FROM favourites WHERE id_cust = '"+ to_string(k)+"' AND id_sub = "+ to_string(i)+"";
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