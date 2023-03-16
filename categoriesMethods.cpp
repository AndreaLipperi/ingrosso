///
// Created by Andrea Lipperi on 14/11/22.
//

#include "categoriesMethods.h"
#include <fstream>
#include <SQLiteCpp/SQLiteCpp.h>
#include <SQLiteCpp/Statement.h>
#include <SQLiteCpp/Database.h>
#include <iostream>
#include <string>
using namespace std;

SQLite::Database db("/Users/andrealipperi/CLionProjects/ingrosso/ingrossodb.sqlite");

TableCategories::TableCategories() {
    string query="CREATE TABLE IF NOT EXISTS categories (id INTEGER PRIMARY KEY, name VARCHAR NOT NULL);";
    db.exec(query);
}
int TableCategories::add(const Categories& cat) {
    data=cat;
    int i=0;
    SQLite::Statement query(db, "SELECT * FROM categories");
    while (query.executeStep()) {
        if (query.getColumn(1).getText() == data.get_name()) {
            i++;
        }
    }
    query.reset();
    if (i==0){
        string query_insert="INSERT INTO categories (name) VALUES ('" + data.get_name() + "');";
        db.exec(query_insert);
        return 1;
    } else {
        return 0;
    }

}
void TableCategories::remove(const string &name) {
    string query="DELETE FROM categories WHERE name = '"+name+"'";
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
void TableCategories::changeName(const string &name, const string &new_name) {
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