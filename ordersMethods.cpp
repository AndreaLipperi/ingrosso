//
// Created by Andrea Lipperi on 14/11/22.
//

#define from_customer 0
#define from_provider 1
#include "ordersMethods.h"
#include "database.h"
#include <SQLiteCpp/SQLiteCpp.h>
#include <SQLiteCpp/Statement.h>
#include <SQLiteCpp/Database.h>
#include <iostream>
#include <string>
using namespace std;


TableOrders::TableOrders() {
    string query="CREATE TABLE IF NOT EXISTS orders (id INTEGER PRIMARY KEY autoincrement, quantity INT NOT NULL,status VARCHAR NOT NULL, date_order VARCHAR NOT NULL, id_prod INT NOT NULL, id_cust INT NOT NULL, id_prov INT NOT NULL, FOREIGN KEY (id_prod) REFERENCES favourites (id), FOREIGN KEY (id_cust) REFERENCES users (id), FOREIGN KEY (id_prov) REFERENCES users (id));";
    db.exec(query);
}
void TableOrders::add(const Orders& order) {
    data=order;
    int control_prov=0;
    int control_cust=0;
    int k=1;
    int j=1;
    SQLite::Statement query_user(db, "SELECT * FROM users");
    while (query_user.executeStep()) {
        if (query_user.getColumn(7).getText() != data.get_id_prov() && control_prov==0) {
            k++;
        } else {
            control_prov=1;
        }
        if (query_user.getColumn(7).getText() != data.get_id_cust() && control_cust==0){
            j++;
        } else {
            control_cust=1;
        }
    }
    query_user.reset();
    string query_insert="INSERT INTO orders (quantity,status, date_order, id_prod,id_cust, id_prov) VALUES (" + to_string(data.get_quantity()) + ",'S','"+data.get_date()+"', " + to_string(data.get_prod()) + ","+
                        to_string(j)+","+
                        to_string(k)+");";
    db.exec(query_insert);
}
void TableOrders::changeStatus(const string& IDuser, const string &IDprov, const string &new_status) {
    int k=1;
    int j=1;

    int control_prov=0;
    int control_cust=0;
    SQLite::Statement query_user(db, "SELECT * FROM user");
    while (query_user.executeStep()) {
        if (query_user.getColumn(7).getText() != data.get_id_prov() && control_prov==0) {
            k++;
        } else {
            control_prov=1;
        }
        if (query_user.getColumn(7).getText() != data.get_id_cust() && control_cust==0){
            j++;
        } else {
            control_cust=1;
        }
    }
    query_user.reset();
        string query = "UPDATE orders SET status = '"+new_status+"' WHERE id_cust = '" + to_string(k) + "' AND id_prov = " +
                       to_string(j) + ";";
        db.exec(query);

}