///
// Created by Andrea Lipperi on 14/11/22.
//

#include "categoriesMethods.h"
#include <fstream>
#include "database.h"
#include <SQLiteCpp/Statement.h>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

TableCategories::TableCategories() {

    //metodo per creare la tabella delle categorie di prodotti nel database
    string query="CREATE TABLE IF NOT EXISTS categories (id INTEGER PRIMARY KEY autoincrement, name VARCHAR NOT NULL);";
    db.exec(query);

}

int TableCategories::number_of_cat(){

    //metodo per sapere il numero di categorie nel db
    int n;
    string query="SELECT count(*) FROM categories";
    n = db.execAndGet(query);
    return n;

}
std::vector<std::string> TableCategories::select() {

    //metodo per prendere i nomi delle categorie dal db
    string category;
    std::vector<std::string> categories;

    //lancio la query
    // e inserisco i valori in un vettore di stringheche poi restituisco
    SQLite::Statement query(db, "SELECT name FROM categories");
    while (query.executeStep()) {
        category = query.getColumn(0).getString();
        categories.push_back(category);

    }
    query.reset();
    return categories;

}