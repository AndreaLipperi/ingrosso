//
// Created by Andrea Lipperi on 14/11/22.
//

#include "favouritesMethods.h"
#include "database.h"
#include <SQLiteCpp/Statement.h>
#include <iostream>
#include <string>
using namespace std;

TableFavourites::TableFavourites() {

    //metodo che crea la tabella dei favourites se questa non esiste nel db
    string query="CREATE TABLE IF NOT EXISTS favourites (id INTEGER PRIMARY KEY autoincrement, id_store INT NOT NULL, id_cust INT NOT NULL, id_prov INT NOT NULL, FOREIGN KEY (id_store) REFERENCES store(id), FOREIGN KEY (id_cust) REFERENCES users (id), FOREIGN KEY (id_prov) REFERENCES users (id));";
    db.exec(query);

}
void TableFavourites::add(const Favourites& fav) {

    //metodo che aggiunge un prodotto alla lista dei favourites
    data=fav;

    //prendo da db i valori di id dell'utente che sta usando il programma
    // e del fornitore del prodotto da inserire
    string query_cust="SELECT id FROM users WHERE username='"+data.get_id_cust()+"'";
    int id_cust=db.execAndGet(query_cust).getInt();

    string query_prov="SELECT id FROM users WHERE username='"+data.get_id_prov()+"'";
    int id_prov=db.execAndGet(query_prov).getInt();

    int id=std::stoi(data.get_id_store());

    //lancio la query che inserisco il prodotto
    string query_insert="INSERT INTO favourites (id_store,id_cust, id_prov) VALUES ("+to_string(id)+", "+to_string(id_cust)+","+to_string(id_prov)+");";
    db.exec(query_insert);

}

void TableFavourites::remove_prod(int id) {

    //metodo che rimuove un prodotto dalla lista
    string query="DELETE FROM favourites WHERE id = "+ to_string(id)+"";
    db.exec(query);

}

string** TableFavourites::select(const string &username) {

    //metodo che prende i valori di tutti i prodotti
    // presenti nella lista dei favourites

    //prendo l'id dell'utente che sta usando il programma
    string query_user="SELECT id FROM users WHERE username ='"+ username+"'";
    int id = db.execAndGet(query_user).getInt();

    //creo una matrice di stringhe cche conterrà i valori
    string** mat=new string *[select_count(username)];
    for (int k = 0; k < select_count(username); k++) {
        mat[k] = new string[5];
    }

    //lancio la query di selezione
    string select="SELECT desc_prod, price_product, username, store.id, favourites.id FROM users,favourites,store WHERE favourites.id_prov=users.id AND id_store=store.id AND id_cust="+to_string(id) +" ORDER BY username;";
    SQLite::Statement query(db,select);

    //inserisco i valori nella matrice e la restituisco
    int m=0;
    int n=0;
    while (query.executeStep()){
        while (n<5) {
            mat[m][n]=query.getColumn(n).getText();
            n++;
        }
        n=0;
        m++;
    }
    return mat;

}

int TableFavourites::select_count(const string &username) {

    //metodo che restituisce il numero di prodotti nella lista

    //prendo il valore dell'id dell'utente che usa il programma
    string query="SELECT id FROM users WHERE username ='"+ username+"'";
    int id = db.execAndGet(query).getInt();

    //lancio la query select count(*) e restituisco il valore
    string query_select_count="SELECT count(*) FROM favourites WHERE id_cust ="+ to_string(id)+"";
    int count = db.execAndGet(query_select_count).getInt();
    return count;

}