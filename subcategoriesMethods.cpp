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

TableProducts::TableProducts()  {

    //funzione che crea la tablella che conterra i prodotti
    //nel database in caso non esista
    string query ="CREATE TABLE IF NOT EXISTS subcategories (id INTEGER PRIMARY KEY autoincrement, name VARCHAR NOT NULL, id_cat INT NOT NULL, FOREIGN KEY(id_cat) REFERENCES categories (id));";
    db.exec(query);

}

std::vector<std::string> TableProducts::select(const string &categories_name) {

    //funzione che seleziona i dati di tutte le sottocategorie
    //appartenenti a una categoria specifica

    //creo un vettore di stringhe che conterrà i valori
    std::vector<std::string> subcategories;
    string subcategory;
    int id;

    //query per prendere il valore dell'id della categoria
    //di cui vogliamo conoscere le sottocategorie

    SQLite::Statement query_cat(db, "SELECT id FROM categories WHERE name='"+categories_name+"'");
    while (query_cat.executeStep()){
        id=query_cat.getColumn(0).getInt();
    }
    query_cat.reset();

    //lancio la query per prendere le sottocategorie
    //popolo i vettore che conterrà i dati
    //restituisco il vettore
    SQLite::Statement query(db, "SELECT name FROM subcategories WHERE id_cat="+ to_string(id)+"");
    while (query.executeStep()) {
        subcategory = query.getColumn(0).getString();
        subcategories.push_back(subcategory);

    }
    query.reset();

    return subcategories;
}

