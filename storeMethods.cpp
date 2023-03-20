//
// Created by Andrea Lipperi on 16/11/22.
//


#include "storeMethods.h"
#include <SQLiteCpp/SQLiteCpp.h>
#include <SQLiteCpp/Statement.h>
#include <SQLiteCpp/Database.h>
#include "database.h"
#include <iostream>
#include <string>
using namespace std;

TableStore::TableStore() {
    string query = "CREATE TABLE IF NOT EXISTS store (id INTEGER PRIMARY KEY autoincrement, available_quantity INT NOT NULL,price_product DOUBLE NOT NULL, desc_prod VARCHAR NOT NULL, id_sub INT NOT NULL, id_prov INT NOT NULL,FOREIGN KEY(id_sub) REFERENCES subcategories (id), FOREIGN KEY (id_prov) REFERENCES users (id))";
    db.exec(query);
}

void TableStore::changeQuantity(const int &id_inter, const string &id_prov,const int &new_quantity){

    int k=1;
    SQLite::Statement query_prov(db, "SELECT * FROM users");
    while (query_prov.executeStep()) {
        if (query_prov.getColumn(2).getText() != id_prov) {
            k++;
        }
    }
    query_prov.reset();
    string query="UPDATE store SET available_quantity = "+ to_string(new_quantity)+" WHERE id_prov = "+to_string(k)+" AND id_intern="+
                                                                                                                    to_string(id_inter)+"";
    db.exec(query);

}

void TableStore::changeDesc(const int &id_inter, const string &id_prov, const string &new_desc){
    int num_result = 0;
    int k=1;
    SQLite::Statement query_prov(db, "SELECT * FROM users");
    while (query_prov.executeStep()) {
        if (query_prov.getColumn(2).getText() != id_prov) {
            k++;
        }
    }
    query_prov.reset();
    string query="UPDATE store SET desc_prod = '"+ new_desc+"' WHERE id_prov = "+
                 to_string(k)+" AND id_intern = "+ to_string(id_inter)+"";
    db.exec(query);
}

void TableStore::add(const Store &store) {
    data=store;
    Subcategories *sub = data.get_prod();
    int i=1;
    SQLite::Statement query_sub(db, "SELECT * FROM subcategories");
    while (query_sub.executeStep()) {
        if (query_sub.getColumn(1).getText() != sub->get_name()) {
            i++;
        }
    }
    query_sub.reset();

    int k=1;
    SQLite::Statement query_prov(db, "SELECT * FROM users");
    while (query_prov.executeStep()) {
        if (query_prov.getColumn(2).getText() != data.get_id_prov()) {
            i++;
        }
    }
    query_prov.reset();
    int j=1;
    SQLite::Statement query_id_inter(db, "SELECT * FROM users");
    while (query_id_inter.executeStep()) {
            j=query_id_inter.getColumn(6).getInt();
    }
    query_id_inter.reset();
    string query_insert="INSERT INTO store (available_quantity, price_product, desc_product,id_sub, id_prov, id_intern) VALUES (" +
            to_string(data.get_quantity()) + ", " + to_string(data.get_price()) + ", '"+data.get_desc()+"', "+
                                                                                                        to_string(i)+", "+
                                                                                                                     to_string(k)+", "+
                                                                                                                                  to_string(j+1)+");";
    db.exec(query_insert);
}

void TableStore::remove(const int &id_inter, const string &id_prov) {

    int k=1;
    SQLite::Statement query_prov(db, "SELECT * FROM users");
    while (query_prov.executeStep()) {
        if (query_prov.getColumn(2).getText() != id_prov) {
            k++;
        }
    }
    query_prov.reset();
    string query="DELETE FROM store WHERE id_prov = "+
                 to_string(k)+" AND id_intern = "+ to_string(id_inter)+"";
    db.exec(query);
}
