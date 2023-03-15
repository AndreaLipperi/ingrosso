//
// Created by Andrea Lipperi on 14/11/22.
//

#include "usersMethods.h"
#include <fstream>
#include <iostream>
#include <SQLiteCpp/SQLiteCpp.h>
#include <SQLiteCpp/Statement.h>
#include <SQLiteCpp/Database.h>
#include <string>
#define accesso 0
#define registrazione 1
using namespace std;

SQLite::Database db("/Users/andrealipperi/CLionProjects/ingrosso/ingosso.db");

TableUsers::TableUsers() {

    SQLite::Statement query(db, "CREATE TABLE IF NOT EXISTS users (id INTEGER PRIMARY KEY, type TEXT NOT NULL,business_name TEXT NOT NULL, address TEXT NOT NULL,city TEXT NOT NULL,email TEXT NOT NULL,password TEXT NOT NULL,username TEXT NOT NULL);");
}
int TableUsers::access_reg(const string &email, const string &psw, int control) {
    //control =0 accesso normale
    //control = 1 per controllo se utente già esistente in caso di registrazione
    int num_found =0;
    SQLite::Statement query(db, "SELECT * FROM users");
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
}
void TableUsers::add(const Users& emp) {
    data=emp;
    SQLite::Statement query(db, "INSERT INTO users (type, business_name, address, city, email, password, username) VALUES ('" + data.get_type() + "', '" + data.get_bus_name() + "', '" + data.get_address() + "', '" + data.get_city() + "', '" + data.get_email() + "', '" + data.get_psw() + "', '" + data.get_username() + "');");
}
void TableUsers::remove(const string &business_name) {
    SQLite::Statement query(db, "SELECT * FROM users");
    while (query.executeStep()){
        if (query.getColumn(2).getText() == business_name) {
            SQLite::Statement query(db,"DELETE FROM users WHERE business_name = '"+business_name+"'");
        }
    }
}
int TableUsers::changePsw(const string &email, const string &new_psw) {
    int num_result = 0;
    int i=0;
    SQLite::Statement query(db, "SELECT * FROM users");
    while (query.executeStep()){
        if (query.getColumn(5).getText() == email) {
            num_result++;
        }
        else {
            i++;
        }
    }
    if (num_result>0) {
        SQLite::Statement query(db, "UPDATE users SET password = '"+new_psw+"' WHERE id = "+ to_string(i)+"");
        return 1;
    } else {
        return 0;
    }
}

string TableUsers::select_username(const string &business_name) {
    string username;
    SQLite::Statement query(db, "SELECT username FROM users WHERE business_name='"+business_name+"'");
    username = query.getColumn(0).getString();
    return username;
}

string TableUsers::select_type(const std::string &email) {
    string type;
    SQLite::Statement query(db, "SELECT type FROM users WHERE email='"+email+"'");
    type = query.getColumn(0).getString();
    return type;
}