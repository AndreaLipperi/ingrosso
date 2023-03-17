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

//SQLite::Database db("/Users/andrealipperi/CLionProjects/ingrosso/ingrossodb.sqlite");

TableUsers::TableUsers() {
    string query ="CREATE TABLE IF NOT EXISTS users (id INTEGER PRIMARY KEY, type VARCHAR NOT NULL,business_name VARCHAR NOT NULL, address VARCHAR NOT NULL,city VARCHAR NOT NULL,email VARCHAR NOT NULL,password VARCHAR NOT NULL,username VARCHAR NOT NULL);";
    db.exec(query);
}
int TableUsers::access_reg(const string &email, const string &psw, int control) {
    //control =0 accesso normale
    //control = 1 per controllo se utente già esistente in caso di registrazione
    int num_found =0;


    SQLite::Statement query(db, "SELECT * FROM users");
    query.reset();
    if (control==accesso) {
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
    data=emp;
    string query="INSERT INTO users (type, business_name, address, city, email, password, username) VALUES ('" + data.get_type() + "', '" + data.get_bus_name() + "', '" + data.get_address() + "', '" + data.get_city() + "', '" + data.get_email() + "', '" + data.get_psw() + "', '" + data.get_username() + "');";

    db.exec(query);
}
void TableUsers::remove(const string &business_name) {
    string query="DELETE FROM users WHERE business_name = '"+business_name+"'";
    db.exec(query);
}
int TableUsers::changePsw(const string &email, const string &new_psw) {
    int num_result = 0;
    int i=0;

    SQLite::Statement query_select(db, "SELECT * FROM users");

    while (query_select.executeStep()){
        if (query_select.getColumn(5).getText() == email) {
            num_result++;
        }
        else {
            i++;
        }
    }
    query_select.reset();
    if (num_result>0) {
        string query="UPDATE users SET password = '"+new_psw+"' WHERE id = "+ to_string(i)+"";
        db.exec(query);
        return 1;
    } else {
        return 0;
    }
}

string TableUsers::select_username(const string &business_name) {
    string username;
    string query="SELECT username FROM users WHERE business_name='"+business_name+"'";
    return db.execAndGet(query);
}

string TableUsers::select_type(const std::string &email) {
    string type;
    string query="SELECT type FROM users WHERE email='"+email+"'";
    return db.execAndGet(query);
}