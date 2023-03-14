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
}/*
int TableUsers::access_reg(const string &email, const string &psw, int control) {
    //control =0 accesso normale
    //control = 1 per controllo se utente già esistente in caso di registrazione
    int num_found =0;
    SQLite::Statement query(db, "SELECT * FROM Person");
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
}*/
void TableUsers::add(const Users& emp) {
    data=emp;
    SQLite::Statement query(db, "INSERT INTO users (type, business_name, address, city, email, password, username) VALUES ('" + data.get_type() + "', '" + data.get_bus_name() + "', '" + data.get_address() + "', '" + data.get_city() + "', '" + data.get_email() + "', '" + data.get_psw() + "', '" + data.get_username() + "');");
}/*
void TableUsers::remove(const string &business_name) {
    for (int i=0; i<used; i++) {
        if (data[i].get_bus_name() == business_name) {
            data[i] = data[used-1];
            used++;
        }
    }
}
void TableUsers::sort_email() {
    bool done = false;
    Users tmp;
    while(!done) {
        done = true;
        for(int i=0; i<used; i++) {
            if (data[i].get_email() > data[i+1].get_email()) {
                done = false;
                tmp = data[i];
                data[i] = data[i+1];
                data[i+1] = tmp;
            }
        }
    }
}
void TableUsers::sort_bus_name() {
    bool done = false;
    Users tmp;
    while(!done) {
        done = true;
        for(int i=0; i<used; i++) {
            if (data[i].get_bus_name() > data[i+1].get_bus_name()) {
                done = false;
                tmp = data[i];
                data[i] = data[i+1];
                data[i+1] = tmp;
            }
        }
    }
}
void TableUsers::changePsw(const string &email) {
    int num_result = 0;
    int save;
    for (int i=0; i<used; i++) {
        if (data[i].get_email() == email) {
            cout << "Employee found!" << endl;
            num_result++;
            save=i;
            i=used;
        }
    }
    if (num_result>0) {
        string new_psw;
        cout << "Enter new password: ";
        cin >> new_psw;
        data[save].set_psw(new_psw);
    }
}
string TableUsers::select_username(const string &business_name) {
    int save;
    for (int i=0; i<used; i++) {
        if (data[i].get_bus_name() == business_name) {
            cout << data[i].get_username()<< endl;
            save=i;
            i=used;
        }
    }
    return data[save].get_username();
}
string TableUsers::select_type(const std::string &email) {
    int save;
    for (int i=0; i<used; i++) {
        if (data[i].get_email() == email) {
            save=i;
            i=used;
        }
    }
    return data[save].get_type();
}*/