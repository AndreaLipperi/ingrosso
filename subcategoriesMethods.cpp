///
// Created by Andrea Lipperi on 14/11/22.
//

#include "subcategoriesMethods.h"
#include <fstream>
#include <SQLiteCpp/SQLiteCpp.h>
#include <SQLiteCpp/Statement.h>
#include <SQLiteCpp/Database.h>
#include <iostream>
#include <string>
using namespace std;

SQLite::Database db("/Users/andrealipperi/CLionProjects/ingrosso/ingrossodb.sqlite");

TableProducts::TableProducts() {
    string query="CREATE TABLE IF NOT EXISTS subcategories (id INTEGER PRIMARY KEY, name VARCHAR NOT NULL,FOREIGN KEY (id_cat) REFERENCES categories (id) NOT NULL);";
    db.exec(query);
}
void TableProducts::add(const Products& prod) {
    data=prod;
    Categories *cat = data.get_cat();
    int i=0;
    SQLite::Statement query(db, "SELECT * FROM categories");
    while (query.executeStep()) {
        if (query.getColumn(1).getText() != cat->get_name()) {
            i++;
        }
    }
    query.reset();
    string query_insert="INSERT INTO subcategories (name, id_cat) VALUES ('" + data.get_name() + "', " + to_string(i) + ");";
    db.exec(query_insert);
}
void TableProducts::remove(const string &name) {
    string query="DELETE FROM subcategories WHERE name = '"+name+"'";
    db.exec(query);
}/*
void TableProducts::sort_id() {
    bool done = false;
    Products tmp;
    while(!done) {
        done = true;
        for(int i=0; i<used; i++) {
            if (data[i].get_name() > data[i+1].get_name()) {
                done = false;
                tmp = data[i];
                data[i] = data[i+1];
                data[i+1] = tmp;
            }
        }
    }
}*/
void TableProducts::changeData(const string &name, const string &new_name) {
    int num_result = 0;
    int i=0;
    SQLite::Statement query_select(db, "SELECT * FROM subcategories");
    while (query_select.executeStep()){
        if (query_select.getColumn(1).getText() == name) {
            num_result++;
        } else {
            i++;
        }
    }
    query_select.reset();
    if (num_result>0) {
        string query="UPDATE subcategories SET name = '"+new_name+"' WHERE id = "+ to_string(i)+"";
        db.exec(query);
    }
}