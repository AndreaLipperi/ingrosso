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

    SQLite::Statement query(db, "SELECT * FROM users");
    query.reset();
    if (control==accesso) {
       while (query.executeStep()){
            if (query.getColumn(5).getText() == email && query.getColumn(6).getText() == psw) {
                num_found++;
            }
        }
        if (num_found == 0) {
            return 0;
        } else {
            return 1;
        }
    } else if(control==registrazione){
        while (query.executeStep()){
            if (query.getColumn(5).getText() == email) {
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

    string query="INSERT INTO users (type, business_name, address, city, email, password, username) VALUES ('" + data.get_type() + "', '" + data.get_bus_name() + "', '" + data.get_address() + "', '" + data.get_city() + "', '" + data.get_email() + "', '" + data.get_psw() + "', '" + data.get_username() + "');";

    db.exec(query);

}
int TableUsers::remove(const string &username, const string &type) {
    //funzione per rimuovere l'utente
    string query_select_id="SELECT id FROM users WHERE username='"+username+"'";
    int id=db.execAndGet(query_select_id).getInt();
    if (type=="F") {
        string query_count_orders="SELECT count(*) FROM orders WHERE status='S' AND id_prov="+to_string(id)+"";
        int count_ord = db.execAndGet(query_count_orders).getInt();
        if (count_ord > 0) {
            return 0;
        }

        string query_count_fav="SELECT count(*) FROM favoutites WHERE id_prov="+to_string(id)+"";
        int count_fav = db.execAndGet(query_count_fav).getInt();
        if (count_fav > 0) {
            return 0;
        }
        string query_count_cart="SELECT count(*) FROM cart WHERE id_prov="+to_string(id)+"";
        int count_cart = db.execAndGet(query_count_cart).getInt();
        if (count_cart > 0) {
            return 0;
        }

        string query_del_store="DELETE FROM store WHERE id_prov = "+to_string(id)+"";
        db.exec(query_del_store);


        string query="DELETE FROM users WHERE username = '"+username+"'";
        db.exec(query);

        return 1;
    } else if (type=="C") {
        string query_count_orders="SELECT count(*) FROM orders WHERE status='S' AND id_cust="+to_string(id)+"";
        int count_ord = db.execAndGet(query_count_orders).getInt();
        if (count_ord > 0) {
            return 0;
        }
        string query_del_cart="DELETE FROM cart WHERE id_user = "+to_string(id)+"";
        db.exec(query_del_cart);

        string query_del_fav="DELETE FROM favourites WHERE id_cust = "+to_string(id)+"";
        db.exec(query_del_fav);

        string query_del_ord="DELETE FROM orders WHERE id_cust = "+to_string(id)+"";
        db.exec(query_del_ord);

        string query_del_user="DELETE FROM users WHERE id = "+to_string(id)+"";
        db.exec(query_del_user);

        return 1;
    }
    return 1;
}
int TableUsers::changeData(const string &email, Users &user) {

    //funzione per cambiare i dati dell'utente

    int num_result;
    int i;

    string query_count="Select count(*) FROM users WHERE email='"+email+"'";
    num_result=db.execAndGet(query_count).getInt();

    if (num_result>0) {

        string query_id="Select id FROM users WHERE email='"+email+"'";
        i=db.execAndGet(query_id).getInt();
        string query="UPDATE users SET address='"+user.get_address()+"', city='"+user.get_city()+"', email='"+user.get_email()+"', password = '"+user.get_psw()+"', username='"+user.get_username()+"' WHERE id = "+ to_string(i)+"";
        db.exec(query);
        return 1;

    } else {

        return 0;

    }
}

string** TableUsers::select_data(const string &username) {
    //funzione per selezionare dal database tutti i dati dell'utente

    string** mat=new string *[1];
    for (int k = 0; k < 1; k++) {
        mat[k] = new string[4];
    }
    string select="SELECT address, city, email, password, business_name FROM users WHERE username='"+username+"';";

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

    string query="SELECT type FROM users WHERE email='"+email+"'";
    string type=db.execAndGet(query).getString();
    return type;

}
string TableUsers::select_username(const std::string &email) {

    string query="SELECT username FROM users WHERE email='"+email+"'";
    string username=db.execAndGet(query).getString();
    return username;

}
string TableUsers::select_email(const std::string &username) {

    string query="SELECT email FROM users WHERE username='"+username+"'";
    string email=db.execAndGet(query).getString();
    return email;

}
void TableUsers::changePsw(const std::string &email, const std::string &new_psw) {
    string query="UPDATE users SET password='"+new_psw+"' WHERE email='"+email+"'";
    db.exec(query);
}