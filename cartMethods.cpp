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
    string query="CREATE TABLE IF NOT EXISTS cart (id INTEGER PRIMARY KEY autoincrement, quantity INT NOT NULL, id_sub INT NOT NULL, id_user INT NOT NULL, id_prov INT NOT NULL, FOREIGN KEY (id_sub) REFERENCES subcategories (id) NOT NULL, FOREIGN KEY (id_user) REFERENCES users (id) NOT NULL, FOREIGN KEY (id_prov) REFERENCES users (id) NOT NULL);";
    db.exec(query);
}
void TableCart::add(const Cart& cart) {
    data=cart;
    Subcategories *prod = data.get_prod();
    int i=1;
    int k=1;
    int j=1;
    SQLite::Statement query_sub(db, "SELECT * FROM subcategories");
    while (query_sub.executeStep()) {
        if (query_sub.getColumn(1).getText() != prod->get_name()) {
            i++;
        }
    }
    query_sub.reset();
    SQLite::Statement query_user(db, "SELECT * FROM user");
    while (query_user.executeStep()) {
        if (query_user.getColumn(2).getText() != data.get_id_user()) {
            k++;
        }
        if (query_user.getColumn(2).getText() != data.get_id_prov()){
            j++;
        }
    }
    query_user.reset();

    string query_insert="INSERT INTO cart (quantity, id_sub, id_prov) VALUES (" + to_string(data.get_quantity()) + ", " + to_string(i) + ","+
                                                                                                                                         to_string(k)+","+
                                                                                                                                                      to_string(j)+");";
    db.exec(query_insert);
}
void TableCart::remove_all(const string &IDuser) {

    string query="DELETE FROM cart WHERE id_user = '"+IDuser+"'";
    db.exec(query);
}
void TableCart::remove_prod(Subcategories &prod,const string &IDuser) {
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

    string query="DELETE FROM cart WHERE id_user = '"+ to_string(k)+"' AND id_sub = "+ to_string(i)+"";
    db.exec(query);
}/*
void TableCart::sort_id_prod() {
  bool done = false;
  Cart tmp;
  while(!done) {
    done = true;
    for(int i=0; i<used; i++) {
      if (data[i].get_prod() > data[i+1].get_prod()) {
        done = false;
        tmp = data[i];
        data[i] = data[i+1];
        data[i+1] = tmp;
      }
    }
  }
}
void TableCart::sort_id_provider() {
  bool done = false;
  Cart tmp;
  while(!done) {
    done = true;
    for(int i=0; i<used; i++) {
      if (data[i].get_id_prov() > data[i+1].get_id_prov()) {
        done = false;
        tmp = data[i];
        data[i] = data[i+1];
        data[i+1] = tmp;
      }
    }
  }
}*/
void TableCart::changeData(const string& IDuser, Subcategories &prod, const string &new_IDprov, const int &new_quantity) {
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
        string query="UPDATE cart SET quantity = "+ to_string(new_quantity)+", id_prov='"+new_IDprov+"' WHERE id = '"+ IDuser+"' AND id_sub = "+
                                                                                                                              to_string(i)+";";
        db.exec(query);
    }
}