//
// Created by Andrea Lipperi on 16/11/22.
//


#include "storeMethods.h"
#include <SQLiteCpp/Statement.h>
#include "database.h"
#include <iostream>
#include <string>
using namespace std;

TableStore::TableStore() {

    //metodo che crea in caso non esista
    //la tabella che contiene il magazzino di tutti i fornitori nel db
    string query = "CREATE TABLE IF NOT EXISTS store (id INTEGER PRIMARY KEY autoincrement, available_quantity INT NOT NULL,price_product DOUBLE NOT NULL, desc_prod VARCHAR NOT NULL, id_sub INT NOT NULL, id_prov INT NOT NULL,FOREIGN KEY(id_sub) REFERENCES subcategories (id), FOREIGN KEY (id_prov) REFERENCES users (id))";
    db.exec(query);

}


void TableStore::changeData(const int &id_store, const string &new_desc, const string &new_price, int new_quantity){

    //metodo per cambiare i valori di un prodotto del proprio magazzino

    //lancio la query
    string query="UPDATE store SET desc_prod = '"+ new_desc+"', price_product="+new_price+", available_quantity="+to_string(new_quantity)+" WHERE id = "+to_string(id_store)+"";
    db.exec(query);

}

void TableStore::add(const Store &store) {

    //metodo per aggiungere un nuovo prodotto al magazzino

    data=store;

    //prendo l'id della sottocategoria alla quale appartiene il prodotto
    string query_sub="SELECT id FROM subcategories WHERE name='"+data.get_prod()+"'";
    int i=db.execAndGet(query_sub);

    //prendo l'id del fornitore proprietario di questo prodotto
    string query_prov="SELECT id FROM users WHERE username = '"+data.get_id_prov()+"'";
    int k=db.execAndGet(query_prov).getInt();

    //prendo il massimo id dei prodotti che ha il fornitore nel suo magazzino
    std::string query_id_inter="SELECT MAX(id_intern) FROM store WHERE id_prov="+ to_string(k)+"";
    int id_intern=db.execAndGet(query_id_inter).getInt();

    //lancio la query di inserimento nel db
    string query_insert="INSERT INTO store (available_quantity, price_product, desc_prod,id_sub, id_prov, id_intern) VALUES (" +data.get_quantity() + ", " + data.get_price() + ", '"+data.get_desc()+"', "+to_string(i)+", "+to_string(k)+", "+to_string(id_intern+1)+");";
    db.exec(query_insert);

}

int TableStore::remove(const int &id_store) {

    //metodo che permette a un fornitore di togliere un prodotto dal suo magazzino

    //controllo che il prodotto in questione non sia all'interno
    // della lista dei preferiti di qualche utente
    //in caso sia presente ritorno 0
    //non permettendo all'utente di cancellare il prodotto
    string query_count_in_fav="SELECT count(*) FROM favourites WHERE id_store="+ to_string(id_store)+"";
    int count_fav=db.execAndGet(query_count_in_fav);
    if (count_fav>0) {
        return 0;
    }

    //controllo che il prodotto non sia presente in qualche ordine in sopeso
    //in caso sia presente ritorno 0
    //non permettendo all'utente di cancellare il prodotto
    string query_count_in_ord="SELECT count(*) FROM orders WHERE id_store="+ to_string(id_store)+" AND status='S'";
    int count_orders=db.execAndGet(query_count_in_ord);
    if (count_orders>0) {
        return 0;
    }

    //controllo che il prodotto non sia all'interno del carrello di qualche utente
    //in caso sia presente ritorno 0
    //non permetteno all'utente di cancellare il prodotto
    string query_count_in_cart="SELECT count(*) FROM cart WHERE id_store="+ to_string(id_store)+"";
    int count_cart=db.execAndGet(query_count_in_cart);
    if (count_cart>0) {
        return 0;
    }

    //se il prodotto non è presente da nessuna parte
    //lancio la query delete e ritorno 1
    string query="DELETE FROM store WHERE id = "+ to_string(id_store)+"";
    db.exec(query);
    return 1;

}

string** TableStore::select(const string &sub_name, const string &disp, const string &order) {

    //metodo per seleziona tutti i prodotti dai vari magazzini
    //appartenenti a una determinata sottocategoria

    //prendo l'id della sottocategoria della quale si vuole vedere i prodotti
    string query_sub="SELECT id FROM subcategories WHERE name='"+sub_name+"'";
    int i = db.execAndGet(query_sub).getInt();

    //creo la matrice che conterrà i valori
    string** mat=new string *[select_count(sub_name,disp)];
    for (int k = 0; k < select_count(sub_name,disp); k++) {
        mat[k] = new string[5];
    }

    //controllo il tipo di disponibilità
    //della quale l'utente vuole vedere i prodotti
    //solo disponibili o tutti quanti
    int n_disp;
    if (disp=="Only Available") {
        n_disp=1;
    } else {
        n_disp=0;
    }

    //controllo i tipo di ordinamento che l'utente cuole usare per vedere i prodotti
    //lancio la query
    //popolo la matrice
    //restituisco la matrice
    string select;
    if (order=="Name Product") {
        select="SELECT desc_prod, price_product, username, CASE WHEN (available_quantity>0) THEN 'Available' ELSE 'Not Available' END,store.id FROM users,store WHERE id_prov=users.id AND id_sub="+
                                   to_string(i)+" AND available_quantity>="+ to_string(n_disp)+" ORDER BY desc_prod;";
    } else if (order=="Price") {
        select="SELECT desc_prod, price_product, username, CASE WHEN (available_quantity>0) THEN 'Available' ELSE 'Not Available' END,store.id FROM users,store WHERE id_prov=users.id AND id_sub="+
                                   to_string(i)+" AND available_quantity>="+ to_string(n_disp)+" ORDER BY price_product;";
    } else if (order=="Provider Name"){
        select="SELECT desc_prod, price_product, username, CASE WHEN (available_quantity>0) THEN 'Available' ELSE 'Not Available' END, store.id FROM users,store WHERE id_prov=users.id AND id_sub="+
                                   to_string(i)+" AND available_quantity>="+ to_string(n_disp)+" ORDER BY username;";
    } else {
        select="SELECT desc_prod, price_product, username, CASE WHEN (available_quantity>0) THEN 'Available' ELSE 'Not DispoAvailablenibile' END,store.id FROM users,store WHERE id_prov=users.id AND id_sub="+
                                   to_string(i)+" AND available_quantity>="+ to_string(n_disp)+" ORDER BY '"+order+"';";
    }
    SQLite::Statement query(db,select);
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


int TableStore::select_count(const string &sub_name, const string &disp) {

    //metodo per sapere quanti prodotti ci sono
    //di una determinata sottocategoria e disponibilità

    //prendo l'id della sottocategoria della quale si vuole vedere i prodotti
    string query_sub="SELECT id FROM subcategories WHERE name='"+sub_name+"'";
    int i = db.execAndGet(query_sub).getInt();

    //controllo il tipo di disponibilità
    //della quale l'utente vuole vedere i prodotti
    //solo disponibili o tutti quanti
    int n_disp;
    if (disp=="Only Available") {
        n_disp=1;
    } else {
        n_disp=0;
    }

    //lancio la query e restituisco il valore
    string query_select_count="SELECT count(*) FROM store WHERE id_sub ="+ to_string(i)+" AND available_quantity>="+to_string(n_disp)+"";
    int count = db.execAndGet(query_select_count).getInt();
    return count;

}

string** TableStore::select_for_prov(const string &username, const string &order) {

    //metodo che prende i valori dei prodotti nel magazzino di un fornitore

    //seleziono l'id del fornitore che sta usando il programma
    string query_select_prov="SELECT id FROM users WHERE username='"+username+"'";
    int id_prov=db.execAndGet(query_select_prov).getInt();

    //prendo la quantità di prodotti presenti
    string query_select_count="SELECT count(*) FROM store WHERE id_prov ="+ to_string(id_prov)+"";
    int count = db.execAndGet(query_select_count).getInt();

    //creo la matrice che conterrà i dati dei prodotti
    string** mat=new string *[count];
    for (int k = 0; k < count; k++) {
        mat[k] = new string[4];
    }

    //controllo i tipo di ordinamento che l'utente
    //vuole usare per vedere i prodotti
    //lancio la query
    //popolo la matrice
    //restituisco la matrice
    string select;
    if (order=="Name Product") {
        select = "SELECT desc_prod, price_product, available_quantity, id FROM store WHERE id_prov=" +
                 to_string(id_prov) + " ORDER BY desc_prod;";
    } else if (order=="Price") {
        select = "SELECT desc_prod, price_product, available_quantity, id FROM store WHERE id_prov=" +
                 to_string(id_prov) + " ORDER BY price_product;";
    } else if (order=="Quantity Available") {
        select = "SELECT desc_prod, price_product, available_quantity, id FROM store WHERE id_prov=" +
                 to_string(id_prov) + " ORDER BY available_quantity;";
    } else {
        select = "SELECT desc_prod, price_product, available_quantity, id FROM store WHERE id_prov=" +
                 to_string(id_prov) + ";";
    }
    SQLite::Statement query(db,select);

    int m=0;
    int n=0;
    while (query.executeStep()){
        while (n<4) {
            mat[m][n]=query.getColumn(n).getText();
            n++;
        }
        n=0;
        m++;
    }
    return mat;

}
int TableStore::select_count_for_prov(const string &username) {

    //metodo per sapere quanti prodotti ha un fornitore in magazzino

    //prendo l'id del fornitore che sta usando il programma
    string query_user="SELECT id FROM users WHERE username='"+username+"'";
    int i = db.execAndGet(query_user).getInt();

    //lancio la query e restituisco il valore
    string query_select_count="SELECT count(*) FROM store WHERE id_prov ="+ to_string(i)+"";
    int count = db.execAndGet(query_select_count).getInt();
    return count;

}
string** TableStore::select_to_modify(int id_store) {

    //metodo che prende i dati di un prodotto per poi poterli modificare

    //creo la matrice che conterrà i dati
    string** mat=new string *[1];
    for (int k = 0; k < 1; k++) {
        mat[k] = new string[3];
    }

    //lancio la query
    //popolo la matrice
    //restituisco la matrice
    string select="SELECT desc_prod, price_product, available_quantity FROM store WHERE id="+ to_string(id_store)+";";
    SQLite::Statement query(db,select);
    int m=0;
    int n=0;
    while (query.executeStep()){
        while (n<3) {
            mat[m][n]=query.getColumn(n).getText();
            n++;
        }
        n=0;
        m++;
    }
    return mat;
    
}