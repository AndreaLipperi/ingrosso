//
// Created by Andrea Lipperi on 14/11/22.
//

#include "usersMethods.h"
#include <fstream>
#include <iostream>
#include "database.h"
#include <SQLiteCpp/SQLiteCpp.h>
#include <SQLiteCpp/Statement.h>
#include <SQLiteCpp/Database.h>
#include <string>
#define accesso 0
#define registrazione 1
using namespace std;

TableUsers::TableUsers() {

    //funzione per creare se non dovesse esistere nel database
    // la tabella che terrà gli utenti del programma
    string query ="CREATE TABLE IF NOT EXISTS users (id INTEGER PRIMARY KEY autoincrement, type VARCHAR NOT NULL,business_name VARCHAR NOT NULL, address VARCHAR NOT NULL,city VARCHAR NOT NULL,email VARCHAR NOT NULL,password VARCHAR NOT NULL,username VARCHAR NOT NULL);";
    db.exec(query);

}

int TableUsers::access_reg(const string &email, const string &psw, int control) {

    //funzione per l'accesso o la registrazione al programma

    //control = 0 accesso normale
    //control = 1 per controllo se utente già esistente in caso di registrazione

    int num_found =0;
    //lancio la query di selezione di tutti gli utenti dal db
    //controllo cosa deve fare il programma
    SQLite::Statement query(db, "SELECT * FROM users");
    query.reset();
    if (control==accesso) {
        //controllo se la mail e la password sono corretti
        //se si restituisco 1 altrimenti 0
       while (query.executeStep()){
            if (query.getColumn(4).getText() == email && query.getColumn(5).getText() == psw) {
                num_found++;
            }
        }
        if (num_found == 0) {
            return 0;
        } else {
            return 1;
        }
    } else if(control==registrazione){
        //controllo che la mail non sia già stata usata per un utente
        //se si restituisco 1 almtrimenti 0
        while (query.executeStep()){
            if (query.getColumn(4).getText() == email) {
                num_found++;
            }
        }
        if (num_found == 0) {
            return 0;
        } else {
            return 1;
        }
    }
    return 0;
}
void TableUsers::add(const Users& emp) {

    //funzione che aggiunge un nuovo utente al database

    data=emp;

    //lancio la query di insert
    string query="INSERT INTO users (type, business_name, address, id_city, email, password, username) VALUES ('" + data.get_type() + "', '" + data.get_bus_name() + "', '" + data.get_address() + "', " + to_string(data.get_city()) + ", '" + data.get_email() + "', '" + data.get_psw() + "', '" + data.get_username() + "');";
    db.exec(query);

}
int TableUsers::remove(const string &username, const string &type) {

    //funzione per rimuovere l'utente

    //seleziono l'id dell'utente che vuole essere cancellato
    string query_select_id="SELECT id FROM users WHERE username='"+username+"'";
    int id=db.execAndGet(query_select_id).getInt();

    //controllo il ripo di utente
    //'F' fornitore, 'C' cliente
    if (type=="F") {
        //controllo che il fornitore non abbia ordini in sospeso
        //se li ha ritorno 0
        //non gli permetto di cancellarsi
        string query_count_orders="SELECT count(*) FROM orders WHERE status='S' AND id_prov="+to_string(id)+"";
        int count_ord = db.execAndGet(query_count_orders).getInt();
        if (count_ord > 0) {
            return 0;
        }

        //controllo che il fornitore non abbia prodotti
        //nella lista dei preferiti di qualcuno
        //se li ha ritorno 0
        //non gli permetto di cancellarsi
        string query_count_fav="SELECT count(*) FROM favoutites WHERE id_prov="+to_string(id)+"";
        int count_fav = db.execAndGet(query_count_fav).getInt();
        if (count_fav > 0) {
            return 0;
        }

        //controllo che il fornitore non abbia prodotti
        //nel carrello di qualcuno
        //se li ha ritorno 0
        //non gli permetto di cancellarsi
        string query_count_cart="SELECT count(*) FROM cart WHERE id_prov="+to_string(id)+"";
        int count_cart = db.execAndGet(query_count_cart).getInt();
        if (count_cart > 0) {
            return 0;
        }

        //se il fornitore non è presente da nessuna
        //parte elimino tutti i suoi prodotti dal magazzino
        string query_del_store="DELETE FROM store WHERE id_prov = "+to_string(id)+"";
        db.exec(query_del_store);

        //infine cancello l'utente stesso
        string query="DELETE FROM users WHERE username = '"+username+"'";
        db.exec(query);

        return 1;

    } else if (type=="C") {

        //controllo che il cliente non abbia ordini in sospeso
        //se li ha restituisco 0
        //non gli permetto di cancellarsi
        string query_count_orders="SELECT count(*) FROM orders WHERE status='S' AND id_cust="+to_string(id)+"";
        int count_ord = db.execAndGet(query_count_orders).getInt();
        if (count_ord > 0) {
            return 0;
        }

        //se non li ha

        //elimino i dati del carrello di quel cliente
        string query_del_cart="DELETE FROM cart WHERE id_user = "+to_string(id)+"";
        db.exec(query_del_cart);

        //elimino i dati della lista dei preferiti del cliente
        string query_del_fav="DELETE FROM favourites WHERE id_cust = "+to_string(id)+"";
        db.exec(query_del_fav);

        //elimino i dati degli ordini di quell'utente
        string query_del_ord="DELETE FROM orders WHERE id_cust = "+to_string(id)+"";
        db.exec(query_del_ord);

        //infine elimino l'utente stesso
        string query_del_user="DELETE FROM users WHERE id = "+to_string(id)+"";
        db.exec(query_del_user);

        return 1;

    }
    return 1;
}
int TableUsers::changeData(const string &username, Users &user) {

    //funzione per cambiare i dati dell'utente

    //prendo i valore dell'id dell'utente che vuole modificare i suoi dati
    string query_id="Select id FROM users WHERE username='"+username+"'";
    int i=db.execAndGet(query_id).getInt();

    //lancio la query di update dei dati
    string query="UPDATE users SET address='"+user.get_address()+"', id_city="+to_string(user.get_city())+", email='"+user.get_email()+"', password = '"+user.get_psw()+"', username='"+user.get_username()+"' WHERE id = "+ to_string(i)+"";
    db.exec(query);
    return 1;

}

string** TableUsers::select_data(const string &username) {

    //funzione per selezionare dal database tutti i dati dell'utente

    //creo la matrice di stringhe che conterrà i dati dell'utente
    string** mat=new string *[1];
    for (int k = 0; k < 1; k++) {
        mat[k] = new string[4];
    }

    //lancio la query
    //popolo la matrice
    //restituisco la matrice
    string select="SELECT address, id_city, email, password, business_name FROM users WHERE username='"+username+"';";
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
string TableUsers::select_type(const std::string &email) {

    //metodo per selezionare il tipo di un utente

    //lancio la query e restituisco il valore
    string query="SELECT type FROM users WHERE email='"+email+"'";
    string type=db.execAndGet(query).getString();
    return type;

}
string TableUsers::select_username(const std::string &email) {

    //metodo per selezionare l'username di un utente

    //lancio la query e restituisco il valore
    string query="SELECT username FROM users WHERE email='"+email+"'";
    string username=db.execAndGet(query).getString();
    return username;

}

void TableUsers::changePsw(const std::string &email, const std::string &new_psw) {

    //metodo per permettera all'utente di cambiare la prorpria password

    //lancio la query di update
    string query="UPDATE users SET password='"+new_psw+"' WHERE email='"+email+"'";
    db.exec(query);

}

string** TableUsers::select_data_all_users(const string &type, const string &city, const string &control) {

    //metodo per prendere i dati di tutti i clienti se fatto da un fornitore
    //o di tutti i fornitore se fatto da un cliente

    //creo la matrice di stringhe che conterrà i dati degli utenti
    string** mat=new string *[select_count_users(type, city)];
    for (int k = 0; k < select_count_users(type, city); k++) {
        mat[k] = new string[5];
    }

    //controllo il tipo di ordinamento richiesto
    string order;
    if (control=="Business Name") {
        order = "business_name";
    } else if (control=="Username") {
        order = "username";
    } else if (control=="Email") {
        order = "email";
    } else if (control=="Address") {
        order = "address";
    } else if (control=="City") {
        order = "name";
    } else {
        order = control;
    }
    //controllo se si vuole sapere tutti gli utenti o di una particolare città
    //lancio la query
    //popolo la matrice
    //restituisco la matrice
    string select;
    if (city=="All") {

        select = "SELECT business_name, username, email, address, name FROM users, cities WHERE cities.id=id_city AND type!='" + type + "' ORDER BY "+order+";";

    } else {
        //prendo il valore dell'id della città scelta
        string select_city="SELECT id FROM cities WHERE name='"+city+"'";
        int id=db.execAndGet(select_city).getInt();

        select = "SELECT business_name, username, email, address, name FROM users, cities WHERE cities.id=id_city AND type!='" + type + "' AND id_city="+to_string(id)+" ORDER BY "+order+";";

    }
    SQLite::Statement query(db, select);
    int m = 0;
    int n = 0;
    while (query.executeStep()) {
        while (n < 5) {
            mat[m][n] = query.getColumn(n).getText();
            n++;
        }
        n = 0;
        m++;
    }
    return mat;

}
int TableUsers::select_count_users(const string &type, const string &city) {
    //metodo che prende il numero di fornitori o clienti di una certa città

    //controllo se si vuole sapere il numero generale o di una particolare città
    string query;
    if (city=="All") {
        query="SELECT count(*) FROM users WHERE type!='"+type+"'";
    } else {
        //prendo il valore dell'id della città scelta
        string select_city="SELECT id FROM cities WHERE name='"+city+"'";
        int id=db.execAndGet(select_city).getInt();
        query="SELECT count(*) FROM users WHERE type!='"+type+"' AND id_city="+ to_string(id)+"";
    }
    int count = db.execAndGet(query).getInt();
    return count;
}