///
// Created by Andrea Lipperi on 14/11/22.
//

#include "subcategoriesMethods.h"
#include <fstream>
#include <iostream>
#include "database.h"
#include <SQLiteCpp/SQLiteCpp.h>
#include <SQLiteCpp/Statement.h>
#include <SQLiteCpp/Database.h>
#include <string>
using namespace std;

//SQLite::Database db("/Users/andrealipperi/CLionProjects/ingrosso/ingrossodb.sqlite");

TableProducts::TableProducts()  {
    string query ="CREATE TABLE IF NOT EXISTS subcategories (id INTEGER PRIMARY KEY autoincrement, name VARCHAR NOT NULL, id_cat INT NOT NULL, FOREIGN KEY(id_cat) REFERENCES categories (id));";
    db.exec(query);
}
void TableProducts::add(const Subcategories& prod) {
    data=prod;
    Categories *cat = data.get_cat();
    int i=1;
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
}
void TableProducts::changeData(const string &name, const string &new_name) {
    int num_result = 0;
    int i=1;
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

std::vector<std::string> TableProducts::select(const string &categories_name) {
    std::vector<std::string> subcategories;
    string subcategory;
    int id;
    SQLite::Statement query_cat(db, "SELECT id FROM categories WHERE name='"+categories_name+"'");
    while (query_cat.executeStep()){
        id=query_cat.getColumn(0).getInt();
    }
    query_cat.reset();
    SQLite::Statement query(db, "SELECT name FROM subcategories WHERE id_cat="+ to_string(id)+"");
    while (query.executeStep()) {
        subcategory = query.getColumn(0).getString();
        subcategories.push_back(subcategory);

    }
    query.reset();
    return subcategories;
}

