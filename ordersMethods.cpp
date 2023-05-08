//
// Created by Andrea Lipperi on 14/11/22.
//

#define only_pending 0
#include "ordersMethods.h"
#include "database.h"
#include <SQLiteCpp/Statement.h>
#include <iostream>
#include <string>
using namespace std;


TableOrders::TableOrders() {

    //metodo che crea la tebbela degli ordini nel db se questa non esiste
    string query="CREATE TABLE IF NOT EXISTS orders (id INTEGER PRIMARY KEY autoincrement, quantity INT NOT NULL,status VARCHAR NOT NULL, date_order VARCHAR NOT NULL, id_store INT NOT NULL, id_cust INT NOT NULL, id_prov INT NOT NULL, id_single_order INT NOT NULL, FOREIGN KEY (id_store) REFERENCES store (id), FOREIGN KEY (id_cust) REFERENCES users (id), FOREIGN KEY (id_prov) REFERENCES users (id));";
    db.exec(query);

}
void TableOrders::add(const Orders& order) {

    //metodo che aggiunge un ordine al database
    data=order;

    //seleziono i valori id dell'utente che usa il programma
    // e del fornitore a cui sarà inviato l'ordine
    string query_prov="SELECT id FROM users WHERE username='"+data.get_id_prov()+"'";
    int id_prov=db.execAndGet(query_prov);

    string query_cust="SELECT id FROM users WHERE username='"+data.get_id_cust()+"'";
    int id_cust=db.execAndGet(query_cust);

    //lancio la query che inserisce l'ordine
    string query_insert="INSERT INTO orders (quantity,status, date_order, id_store,id_cust, id_prov, id_single_order) VALUES (" + to_string(data.get_quantity()) + ",'S','"+data.get_date()+"', " + to_string(data.get_prod()) + ","+
                        to_string(id_cust)+","+
                        to_string(id_prov)+","+ to_string(data.get_id())+");";

    db.exec(query_insert);

}

void TableOrders::changeStatus(const string& username,const string &cod_order, const string &new_status) {
    //metodo che cambia lo status dell'ordine da sospeso(S) a approvato(A) o rifiutato(D)

    //prendo l'id dell'utente che sta usando il programma
    string query_user="SELECT id FROM users WHERE username ='"+ username+"'";
    int id = db.execAndGet(query_user).getInt();
    int order=stoi(cod_order);

    //lancio la query di modifica
    string query = "UPDATE orders SET status = '"+new_status+"' WHERE id_single_order = " + to_string(order) + " AND id_prov = " +to_string(id) + ";";
    db.exec(query);

}

int TableOrders::select_count(const string &username, int control) {

    //metodo che prende quanti ordini ci sono in db,
    // con la scelta di poter vedere o solo quelli in sopseso(only_pending)
    //o tutti

    //prendo il valore dell'id dell'utente che sta usando il programma
    string query="SELECT id FROM users WHERE username ='"+ username+"'";
    int id = db.execAndGet(query).getInt();
    string query_select_count;

    //controllo di quali ordini si vuole sapere la quantità,
    // lancio la query
    //e restituisco il valore
    if (control==only_pending) {
        query_select_count =
                "SELECT count(DISTINCT id_single_order) FROM orders WHERE id_prov =" + to_string(id) +
                " AND status='S'";
    } else {
        query_select_count =
                "SELECT count(DISTINCT id_single_order) FROM orders WHERE id_prov =" + to_string(id) +
                "";
    }
    int count = db.execAndGet(query_select_count).getInt();
    return count;

}
int TableOrders::select_count_for_client(const string &username, int control) {

    //metodo usato per la parte relaitva ai clienti
    // per sapere quanti ordini ci sono nel databse

    //prendo il vallore dell'id dell'utente che usa il programma
    string query="SELECT id FROM users WHERE username ='"+ username+"'";
    int id = db.execAndGet(query).getInt();

    //controllo di quali ordini si vuole sapere la quantità,
    // lancio la query
    //e restituisco il valore
    string query_select_count;
    if (control==only_pending) {
        query_select_count = "SELECT count(DISTINCT id_single_order) FROM orders WHERE id_cust =" + to_string(id) +
                             " AND status='S'";
    } else {

        query_select_count = "SELECT count(DISTINCT id_single_order) FROM orders WHERE id_cust =" + to_string(id) +
                             "";
    }
    int count = db.execAndGet(query_select_count).getInt();
    return count;

}

string** TableOrders::select(const string &username, int control, const string &order) {

    //metodo che restituisce una matrice di stringhe
    // contenente i dati generali degli ordini di un fornitore

    //prendo il valore dell'id dell'utente che sta usando il programma
    string query_user="SELECT id FROM users WHERE username ='"+username+"'";
    int id = db.execAndGet(query_user).getInt();

    //creo una matrice di stringhe che conterrà i valori
    string** mat=new string *[select_count(username, control)];
    string select;

    //controllo di quali tipo di ordini si vuole sapere i dati
    //only_pending=0 solo in sospeso
    //poi quindi creo le colonne della matrice
    //lancio la query e popolo la matrice per poi lanciarla
    if (control==only_pending) {
        for (int k = 0; k < select_count(username, control); k++) {
            mat[k] = new string[3];
        }
        if (order == "Code Order") {
            select =
                    "SELECT DISTINCT id_single_order, username, date_order FROM users, orders WHERE id_cust=users.id AND status='S' AND id_prov=" +
                    to_string(id) + " ORDER BY id_single_order";
        } else if (order == "Customer Name") {
            select =
                    "SELECT DISTINCT id_single_order, username, date_order FROM users, orders WHERE id_cust=users.id AND status='S' AND id_prov=" +
                    to_string(id) + " ORDER BY username";
        } else if (order == "Date Order") {
            select =
                    "SELECT DISTINCT id_single_order, username, date_order FROM users, orders WHERE id_cust=users.id AND status='S' AND id_prov=" +
                    to_string(id) + " ORDER BY date_order";
        } else {
            select =
                    "SELECT DISTINCT id_single_order, username, date_order FROM users, orders WHERE id_cust=users.id AND status='S' AND id_prov=" +
                    to_string(id) + "";
        }
        SQLite::Statement query(db, select);
        int m = 0;
        int n = 0;
        while (query.executeStep()) {
            while (n < 3) {
                mat[m][n] = query.getColumn(n).getText();
                n++;
            }
            n = 0;
            m++;
        }
    } else {
        for (int k = 0; k < select_count(username, control); k++) {
            mat[k] = new string[4];
        }
        if (order == "Code Order") {
            select =
                    "SELECT DISTINCT id_single_order, username, date_order, CASE WHEN (status='S') THEN 'Pending' WHEN (status='D') THEN 'Denied' ELSE 'Accepted' END FROM users, orders WHERE id_cust=users.id AND id_prov="+to_string(id)+" ORDER BY id_single_order";
        } else if (order == "Customer Name") {
            select =
                    "SELECT DISTINCT id_single_order, username, date_order, CASE WHEN (status='S') THEN 'Pending' WHEN (status='D') THEN 'Denied' ELSE 'Accepted' END FROM users, orders WHERE id_cust=users.id AND id_prov="+to_string(id)+" ORDER BY username";
        } else if (order == "Date Order") {
            select =
                    "SELECT DISTINCT id_single_order, username, date_order, CASE WHEN (status='S') THEN 'Pending' WHEN (status='D') THEN 'Denied' ELSE 'Accepted' END FROM users, orders WHERE id_cust=users.id AND id_prov="+to_string(id)+" ORDER BY date_order";
        } else {
            select =
                    "SELECT DISTINCT id_single_order, username, date_order, CASE WHEN (status='S') THEN 'Pending' WHEN (status='D') THEN 'Denied' ELSE 'Accepted' END FROM users, orders WHERE id_cust=users.id AND id_prov="+to_string(id)+"";
        }
        SQLite::Statement query(db, select);
        int m = 0;
        int n = 0;
        while (query.executeStep()) {
            while (n < 4) {
                mat[m][n] = query.getColumn(n).getText();
                n++;
            }
            n = 0;
            m++;
        }
    }
    return mat;

}

int TableOrders::select_id(const string &username_prov) {

    //metodo per sapere l'id generale dell'ultimo ordine arrivato al fornitore

    //prendo il valore dell'id dell'utente che sta usando il programma
    string query="SELECT id FROM users WHERE username ='"+ username_prov+"'";
    int id = db.execAndGet(query).getInt();

    //lancio la query e restituisco il valore
    string query_id="SELECT MAX(id_single_order) FROM orders WHERE id_prov="+ to_string(id)+"";
    int id_single_order=db.execAndGet(query_id).getInt();
    return id_single_order;

}
string** TableOrders::select_single_order(const string &username, const string &cod_order) {

    //metodo che prende i dati di un singolo ordine selezionato in precedenza

    //prendo l'id dell'utente che sta usando il programma
    string query_user="SELECT id FROM users WHERE username ='"+username+"'";
    int id = db.execAndGet(query_user).getInt();

    //creo la matrice di stringhe che conterrà i valori
    string** mat=new string *[select_count_single_order(username,cod_order)];
    for (int k = 0; k < select_count_single_order(username,cod_order); k++) {
        mat[k] = new string[4];
    }

    //lancio la query
    //popolo la matrice
    //restituisco la matrice
    int order=stoi(cod_order);
    string select="SELECT quantity,price_product*quantity,desc_prod,available_quantity  FROM store, orders WHERE id_store=store.id AND orders.id_prov="+to_string(id)+" AND id_single_order="+to_string(order)+"";
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

int TableOrders::select_count_single_order(const string &username, const string &cod_order) {

    //metodo per sapere quanti prodotti sono presenti
    // all'interno di un singolo ordine

    //prendo lò'id dell'utente che usa il programma
    string query="SELECT id FROM users WHERE username ='"+ username+"'";
    int id = db.execAndGet(query).getInt();

    //lancio la query e restituisco il valore
    int order=stoi(cod_order);
    string query_select_count="SELECT count(*) FROM orders WHERE id_prov ="+ to_string(id)+" AND id_single_order="+to_string(order)+"";
    int count = db.execAndGet(query_select_count).getInt();
    return count;

}

string **TableOrders::select_for_client(const string &username, int control, const string &order) {

    //matodo che prende i dati generali degli ordini di un cliente

    //prendo il valore dell'id dell'utente che sta usando il programma
    string query_user="SELECT id FROM users WHERE username ='"+username+"'";
    int id = db.execAndGet(query_user).getInt();

    //creo la matrice di stringhe che conterrà i valori
    string** mat=new string *[select_count_for_client(username, control)];

    //controllo la tipologia di ordini dei quali si vuole sapere i dati
    //only_pending=0 solo in sospeso
    //setto il numero di colonne della matrice
    //lancio la query
    //popolo la matrice
    //restituisco la matrice
    string select;
    if (control==only_pending) {
        for (int k = 0; k < select_count_for_client(username, control); k++) {
            mat[k] = new string[3];
        }
        if (order == "Code Order") {
            select =
                    "SELECT DISTINCT id_single_order, username, date_order FROM users, orders WHERE id_prov=users.id AND status='S' AND id_cust=" +
                    to_string(id) + " ORDER BY id_single_order";
        } else if (order == "Provider Name") {
            select =
                    "SELECT DISTINCT id_single_order, username, date_order FROM users, orders WHERE id_prov=users.id AND status='S' AND id_cust=" +
                    to_string(id) + " ORDER BY username";
        } else if (order == "Date Order") {
            select =
                    "SELECT DISTINCT id_single_order, username, date_order FROM users, orders WHERE id_prov=users.id AND status='S' AND id_cust=" +
                    to_string(id) + " ORDER BY date_order";
        } else {
            select =
                    "SELECT DISTINCT id_single_order, username, date_order FROM users, orders WHERE id_prov=users.id AND status='S' AND id_cust=" +
                    to_string(id) + "";
        }
        SQLite::Statement query(db, select);
        int m = 0;
        int n = 0;
        while (query.executeStep()) {
            while (n < 3) {
                mat[m][n] = query.getColumn(n).getText();
                n++;
            }
            n = 0;
            m++;
        }
    } else {
        for (int k = 0; k < select_count_for_client(username, control); k++) {
            mat[k] = new string[4];
        }
        if (order == "Code Order") {
            select =
                    "SELECT DISTINCT id_single_order, username, date_order, CASE WHEN (status='S') THEN 'Pending' WHEN (status='D') THEN 'Denied' ELSE 'Accepted' END FROM users, orders WHERE id_prov=users.id AND id_cust="+to_string(id)+" ORDER BY id_single_order";
        } else if (order == "Customer Name") {
            select =
                    "SELECT DISTINCT id_single_order, username, date_order, CASE WHEN (status='S') THEN 'Pending' WHEN (status='D') THEN 'Denied' ELSE 'Accepted' END FROM users, orders WHERE id_prov=users.id AND id_cust="+to_string(id)+" ORDER BY username";
        } else if (order == "Date Order") {
            select =
                    "SELECT DISTINCT id_single_order, username, date_order, CASE WHEN (status='S') THEN 'Pending' WHEN (status='D') THEN 'Denied' ELSE 'Accepted' END FROM users, orders WHERE id_prov=users.id AND id_cust="+to_string(id)+" ORDER BY date_order";
        } else {
            select =
                    "SELECT DISTINCT id_single_order, username, date_order, CASE WHEN (status='S') THEN 'Pending' WHEN (status='D') THEN 'Denied' ELSE 'Accepted' END FROM users, orders WHERE id_prov=users.id AND id_cust="+to_string(id)+"";
        }
        SQLite::Statement query(db, select);
        int m = 0;
        int n = 0;
        while (query.executeStep()) {
            while (n < 4) {
                mat[m][n] = query.getColumn(n).getText();
                n++;
            }
            n = 0;
            m++;
        }

    }
    return mat;

}

int TableOrders::select_count_single_order_for_client(const string &username, const string &cod_order, const string &us_prov) {

    //metodo che prende il numero di prodotti
    //all'interno di un singolo ordine per i clienti

    //prendo l'id dell'utente che sta usando il programma
    string query="SELECT id FROM users WHERE username ='"+ username+"'";
    int id = db.execAndGet(query).getInt();

    //prendo l'id del fornitore al quale appartine il prodotto
    string query_prov="SELECT id FROM users WHERE username ='"+ us_prov+"'";
    int id_prov = db.execAndGet(query_prov).getInt();

    //lancio la query e restituisco il valore
    int order=stoi(cod_order);
    string query_select_count="SELECT count(*) FROM orders WHERE id_cust ="+ to_string(id)+" AND id_single_order="+to_string(order)+" AND id_prov="+ to_string(id_prov)+"";
    int count = db.execAndGet(query_select_count).getInt();
    return count;

}

string** TableOrders::select_single_order_for_client(const std::string &username, const std::string &cod_order, const string &us_prov)  {

    //metodo che prende i dati di un singolo ordine selezionato in precedenza

    //prendo l'id dell'utente che sta usando il programma
    string query_user="SELECT id FROM users WHERE username ='"+username+"'";
    int id = db.execAndGet(query_user).getInt();

    //prendo l'id del fornitore al quale è inviato l'ordine
    string query_prov="SELECT id FROM users WHERE username ='"+us_prov+"'";
    int id_prov = db.execAndGet(query_prov).getInt();

    //creo la matrice che conterrà i dati
    string** mat_client=new string *[select_count_single_order_for_client(username,cod_order,us_prov)];
    for (int k = 0; k < select_count_single_order_for_client(username,cod_order,us_prov); k++) {
        mat_client[k] = new string[3];
    }

    //lancio la query
    //popolo la matrice
    //restituisco i dati
    int order=stoi(cod_order);
    string select="SELECT quantity,price_product*quantity,desc_prod  FROM store, orders WHERE id_store=store.id AND orders.id_cust="+to_string(id)+" AND id_single_order="+
           to_string(order)+" AND orders.id_prov="+ to_string(id_prov)+"";

    SQLite::Statement query(db,select);

    int m=0;
    int n=0;
    while (query.executeStep()){
        while (n<3) {
            mat_client[m][n]=query.getColumn(n).getText();
            n++;
        }
        n=0;
        m++;
    }
    return mat_client;

}
void TableOrders::cancel_order(const std::string &username, const std::string &cod_order, const string &us_prov) {

    //metodo che permette a un utente di annullare il proprio ordine

    //prendo l'id dell'utente che sta usando il programma
    string query_user="SELECT id FROM users WHERE username ='"+username+"'";
    int id = db.execAndGet(query_user).getInt();

    //prendo l'id del fornitore al quale è stato inviato l'ordine
    string query_prov="SELECT id FROM users WHERE username ='"+us_prov+"'";
    int id_prov = db.execAndGet(query_prov).getInt();

    //lancio la query delete
    int order=stoi(cod_order);
    string cancel="DELETE FROM orders WHERE id_single_order="+ to_string(order)+ " AND id_cust="+ to_string(id) +" AND id_prov="+to_string(id_prov)+"";
    db.exec(cancel);

}
