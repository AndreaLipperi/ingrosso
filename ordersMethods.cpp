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
    string query="CREATE TABLE IF NOT EXISTS orders (id INTEGER PRIMARY KEY autoincrement, quantity INT NOT NULL,satus VARCHAR NOT NULL, date_order DATE NOT NULL, id_prod INT NOT NULL, id_cust INT NOT NULL, id_prov INT NOT NULL, FOREIGN KEY (id_prod) REFERENCES store (id), FOREIGN KEY (id_cust) REFERENCES users (id), FOREIGN KEY (id_prov) REFERENCES users (id));";
    db.exec(query);
}
void TableOrders::add(const Orders& order) {
    data=order;
    Store *prod = data.get_prod();
    int i=1;
    int k=1;
    int j=1;
    SQLite::Statement query_user(db, "SELECT * FROM user");
    while (query_user.executeStep()) {
        if (query_user.getColumn(2).getText() != data.get_id_cust()) {
            k++;
        }
        if (query_user.getColumn(2).getText() != data.get_id_prov()){
            j++;
        }
    }
    query_user.reset();

    SQLite::Statement query_sub(db, "SELECT * FROM store WHERE id_prov = "+ to_string(j)+"");
    while (query_sub.executeStep()) {
        if (query_sub.getColumn(1).getText() != prod->get_desc()) {
            i++;
        }
    }
    query_sub.reset();
    string query_insert="INSERT INTO orders (quantity,status, id_prod,id_cust, id_prov) VALUES (" + to_string(data.get_quantity()) + ",'S', " + to_string(i) + ","+
                        to_string(k)+","+
                        to_string(j)+");";
    db.exec(query_insert);
}
void TableOrders::changeStatus(const string& IDuser, const string &IDprov, const string &new_status) {
    int k=1;
    int j=1;
    SQLite::Statement query_user(db, "SELECT * FROM user");
    while (query_user.executeStep()) {
        if (query_user.getColumn(2).getText() != IDuser) {
            k++;
        }
        if (query_user.getColumn(2).getText() != IDprov){
            j++;
        }
    }
    query_user.reset();
        string query = "UPDATE orders SET status = '"+new_status+"' WHERE id_cust = '" + to_string(k) + "' AND id_prov = " +
                       to_string(j) + ";";
        db.exec(query);

}