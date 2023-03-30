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
    string query="CREATE TABLE IF NOT EXISTS cart (id INTEGER PRIMARY KEY autoincrement, quantity INT NOT NULL, id_store INT NOT NULL, id_user INT NOT NULL, id_prov INT NOT NULL, FOREIGN KEY (id_user) REFERENCES users (id), FOREIGN KEY (id_prov) REFERENCES users (id));";
    db.exec(query);
}
void TableCart::add(const Cart& cart) {
    data=cart;
    int k=1;
    int j=1;
    SQLite::Statement query_user(db, "SELECT * FROM users");
    while (query_user.executeStep()) {
        if (query_user.getColumn(2).getText() != data.get_id_prov()) {
            k++;
        }
        if (query_user.getColumn(2).getText() != data.get_id_user()){
            j++;
        }
    }
    query_user.reset();
    int id=std::stoi(data.get_id_store());

    string query_insert="INSERT INTO cart (quantity, id_store,id_user, id_prov) VALUES (" + to_string(data.get_quantity()) + ", " + to_string(id) + ","+
                                                                                                                                         to_string(j)+","+
                                                                                                                                                      to_string(k)+");";
    db.exec(query_insert);
}
void TableCart::remove_all(const string &IDuser) {

    string query="DELETE FROM cart WHERE id_user = '"+IDuser+"'";
    db.exec(query);
}
void TableCart::remove_prod(Store &prod,const string &IDuser, const string &IDprov) {
    int i=1;
    int j=0;
    int k=1;
    SQLite::Statement query_user(db, "SELECT * FROM user");
    while (query_user.executeStep()) {
        if (query_user.getColumn(2).getText() != IDuser) {
            k++;
        }
        if (query_user.getColumn(2).getText() != IDprov) {
            j++;
        }
    }
    query_user.reset();
    SQLite::Statement query_sub(db, "SELECT * FROM store WHERE id_prov="+ to_string(j)+"");
    while (query_sub.executeStep()) {
        if (query_sub.getColumn(3).getText() != prod.get_desc()) {
            i++;
        }
    }
    query_sub.reset();
    string query="DELETE FROM cart WHERE id_user = '"+ to_string(k)+"' AND id_prod = "+ to_string(i)+"";
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