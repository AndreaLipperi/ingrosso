//
// Created by Andrea Lipperi on 14/11/22.
//

#include "cartMethods.h"
#include "database.h"
#include <SQLiteCpp/Statement.h>
#include <iostream>
#include <string>

using namespace std;

TableCart::TableCart() {
    //query per creare in caso non esista la tabella del carrello nel db
    string query="CREATE TABLE IF NOT EXISTS cart (id INTEGER PRIMARY KEY autoincrement, quantity INT NOT NULL, id_store INT NOT NULL, id_user INT NOT NULL, id_prov INT NOT NULL, FOREIGN KEY (id_user) REFERENCES users (id),FOREIGN KEY (id_prov) REFERENCES users (id), FOREIGN KEY (id_store) REFERENCES store (id));";
    db.exec(query);
}

void TableCart::add(const Cart& cart) {

    //metodo per aggiungere al carrello un nuovo prodotto
    data=cart;
    //prendo l'id dell'utente che sta usando il programma e
    // del fornitore del prodotto che sto mettendo nel carrello
    string query_user="SELECT id FROM users WHERE username='"+data.get_id_user()+"'";
    int id_user=db.execAndGet(query_user);

    string query_prov="SELECT id FROM users WHERE username='"+data.get_id_prov()+"'";
    int id_prov=db.execAndGet(query_prov);

    int id=std::stoi(data.get_id_store());

    //inserisco i dati nel db
    string query_insert="INSERT INTO cart (quantity, id_store,id_user, id_prov) VALUES (" + to_string(data.get_quantity()) + ", " + to_string(id) + ","+ to_string(id_user)+","+to_string(id_prov)+")";
    cout << query_insert;
    db.exec(query_insert);

}

void TableCart::remove_all(const string &username) {

    //metodo per rimuovere tutti i prodotti dal carello
    // una volta effettuato l'ordine da quest'ultimo

    //prendo l'id dell'utente che sta usando il programma
    string query_select="SELECT id FROM users WHERE username ='"+ username+"'";
    int id = db.execAndGet(query_select).getInt();

    //lancio la query di delete dal db
    string query="DELETE FROM cart WHERE id_user = "+ to_string(id)+"";
    db.exec(query);

}

void TableCart::remove_prod(int id) {

    //metodo per eliminare un solo prodotto dal carrello

    string query="DELETE FROM cart WHERE id = "+ to_string(id)+"";
    db.exec(query);

}

int TableCart::select_count(const string &username) {

    //metodo per sapere quanti prodotti ha l'utente nel carrello

    //prendo l'id dell'utente che sta usando il programma
    string query="SELECT id FROM users WHERE username ='"+ username+"'";
    int id = db.execAndGet(query).getInt();

    //lancio la query select count(*) e restituisco il valore
    string query_select_count="SELECT count(*) FROM cart WHERE id_user ="+ to_string(id)+"";
    int count = db.execAndGet(query_select_count).getInt();
    return count;

}

string** TableCart::select(const string &username) {

    //metodo per prendere i valori dei prodotti nel carrello dell'utente

    //prendo l'id dell'utente che sta usando il programma
    string query_user="SELECT id FROM users WHERE username ='"+ username+"'";
    int id = db.execAndGet(query_user).getInt();

    //creo una matrice di stringhe che conterrà i valori
    string** mat=new string *[select_count(username)];
    for (int k = 0; k < select_count(username); k++) {
        mat[k] = new string[6];
    }

    //lancio la query che prende i valori dal db
    string select="SELECT desc_prod, price_product, username, quantity, store.id,cart.id FROM users,cart,store WHERE id_store=store.id AND store.id_prov=users.id AND id_user="+to_string(id) +" ORDER BY username;";
    SQLite::Statement query(db,select);

    //inserisco i valori all'interno della matrice e la restituisco
    int m=0;
    int n=0;
    while (query.executeStep()){
        while (n<6) {
            mat[m][n]=query.getColumn(n).getText();
            n++;
        }
        n=0;
        m++;
    }
    return mat;

}
