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
    string query="CREATE TABLE IF NOT EXISTS orders (id INTEGER PRIMARY KEY autoincrement, quantity INT NOT NULL,status VARCHAR NOT NULL, date_order VARCHAR NOT NULL, id_store INT NOT NULL, id_cust INT NOT NULL, id_prov INT NOT NULL, id_single_order INT NOT NULL, FOREIGN KEY (id_store) REFERENCES store (id), FOREIGN KEY (id_cust) REFERENCES users (id), FOREIGN KEY (id_prov) REFERENCES users (id));";
    db.exec(query);
}
void TableOrders::add(const Orders& order) {
    data=order;
    int control_prov=0;
    int control_cust=0;
    int k=1;
    int j=1;
    string query_prov="SELECT id FROM users WHERE username='"+data.get_id_prov()+"'";
    int id_prov=db.execAndGet(query_prov);

    string query_cust="SELECT id FROM users WHERE username='"+data.get_id_cust()+"'";
    int id_cust=db.execAndGet(query_cust);

    string query_insert="INSERT INTO orders (quantity,status, date_order, id_store,id_cust, id_prov, id_single_order) VALUES (" + to_string(data.get_quantity()) + ",'S','"+data.get_date()+"', " + to_string(data.get_prod()) + ","+
                        to_string(id_cust)+","+
                        to_string(id_prov)+","+ to_string(data.get_id())+");";


    db.exec(query_insert);
}
void TableOrders::changeStatus(const string& username,const string &cod_order, const string &new_status) {
    string query_user="SELECT id FROM users WHERE username ='"+ username+"'";
    int id = db.execAndGet(query_user).getInt();
    int order=stoi(cod_order);
    string query = "UPDATE orders SET status = '"+new_status+"' WHERE id_single_order = " + to_string(order) + " AND id_prov = " +to_string(id) + ";";
    db.exec(query);

}

int TableOrders::select_count(const string &username) {
    string query="SELECT id FROM users WHERE username ='"+ username+"'";
    int id = db.execAndGet(query).getInt();
    string query_select_count="SELECT count(DISTINCT id_single_order) FROM orders WHERE id_prov ="+ to_string(id)+" AND status='S'";
    int count = db.execAndGet(query_select_count).getInt();
    return count;
}
int TableOrders::select_count_for_client(const string &username) {
    string query="SELECT id FROM users WHERE username ='"+ username+"'";
    int id = db.execAndGet(query).getInt();
    string query_select_count="SELECT count(DISTINCT id_single_order) FROM orders WHERE id_cust ="+ to_string(id)+" AND status='S'";
    int count = db.execAndGet(query_select_count).getInt();
    return count;
}

string** TableOrders::select(const string &username, const string &order) {
    string query_user="SELECT id FROM users WHERE username ='"+username+"'";
    int id = db.execAndGet(query_user).getInt();

    string** mat=new string *[select_count(username)];
    for (int k = 0; k < select_count(username); k++) {
        mat[k] = new string[3];
    }
    string select;
    if (order=="Code Order") {
        select ="SELECT DISTINCT id_single_order, username, date_order FROM users, orders WHERE id_cust=users.id AND status='S' AND id_prov=" +
                to_string(id) + " ORDER BY id_single_order";
    } else if   (order=="Customer Name") {
        select ="SELECT DISTINCT id_single_order, username, date_order FROM users, orders WHERE id_cust=users.id AND status='S' AND id_prov=" +
                to_string(id) + " ORDER BY username";
    } else if (order=="Date Order") {
        select ="SELECT DISTINCT id_single_order, username, date_order FROM users, orders WHERE id_cust=users.id AND status='S' AND id_prov=" +
                to_string(id) + " ORDER BY date_order";
    } else {
        select ="SELECT DISTINCT id_single_order, username, date_order FROM users, orders WHERE id_cust=users.id AND status='S' AND id_prov=" +
                to_string(id) + "";
    }
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
int TableOrders::select_id(const string &username_prov) {
    string query="SELECT id FROM users WHERE username ='"+ username_prov+"'";

    int id = db.execAndGet(query).getInt();
    string query_id="SELECT MAX(id_single_order) FROM orders WHERE id_prov="+ to_string(id)+"";

    int id_single_order=db.execAndGet(query_id).getInt();
    return id_single_order;
}
string** TableOrders::select_single_order(const string &username, const string &cod_order) {
    string query_user="SELECT id FROM users WHERE username ='"+username+"'";
    int id = db.execAndGet(query_user).getInt();

    string** mat=new string *[select_count_single_order(username,cod_order)];
    for (int k = 0; k < select_count_single_order(username,cod_order); k++) {
        mat[k] = new string[4];
    }
    string select;
    int order=stoi(cod_order);
    select="SELECT quantity,price_product*quantity,desc_prod,available_quantity  FROM store, orders WHERE id_store=store.id AND orders.id_prov="+to_string(id)+" AND id_single_order="+
                                                                                                                                                        to_string(order)+"";

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
    string query="SELECT id FROM users WHERE username ='"+ username+"'";
    int id = db.execAndGet(query).getInt();
    int order=stoi(cod_order);
    string query_select_count="SELECT count(*) FROM orders WHERE id_prov ="+ to_string(id)+" AND id_single_order="+
                                                                                           to_string(order)+"";
    int count = db.execAndGet(query_select_count).getInt();
    return count;
}

string **TableOrders::select_for_client(const string &username, const string &order) {
    string query_user="SELECT id FROM users WHERE username ='"+username+"'";
    int id = db.execAndGet(query_user).getInt();

    string** mat=new string *[select_count_for_client(username)];
    for (int k = 0; k < select_count_for_client(username); k++) {
        mat[k] = new string[3];
    }
    string select;
    if (order=="Code Order") {
        select ="SELECT DISTINCT id_single_order, username, date_order FROM users, orders WHERE id_prov=users.id AND status='S' AND id_cust=" +
                to_string(id) + " ORDER BY id_single_order";
    } else if   (order=="Provider Name") {
        select ="SELECT DISTINCT id_single_order, username, date_order FROM users, orders WHERE id_prov=users.id AND status='S' AND id_cust=" +
                to_string(id) + " ORDER BY username";
    } else if (order=="Date Order") {
        select ="SELECT DISTINCT id_single_order, username, date_order FROM users, orders WHERE id_prov=users.id AND status='S' AND id_cust=" +
                to_string(id) + " ORDER BY date_order";
    } else {
        select ="SELECT DISTINCT id_single_order, username, date_order FROM users, orders WHERE id_prov=users.id AND status='S' AND id_cust=" +
                to_string(id) + "";
    }
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

int TableOrders::select_count_single_order_for_client(const string &username, const string &cod_order, const string &us_prov) {
    string query="SELECT id FROM users WHERE username ='"+ username+"'";

    int id = db.execAndGet(query).getInt();
    string query_prov="SELECT id FROM users WHERE username ='"+ us_prov+"'";

    int id_prov = db.execAndGet(query_prov).getInt();
    int order=stoi(cod_order);
    string query_select_count="SELECT count(*) FROM orders WHERE id_cust ="+ to_string(id)+" AND id_single_order="+
                              to_string(order)+" AND id_prov="+ to_string(id_prov)+"";

    int count = db.execAndGet(query_select_count).getInt();
    return count;
}

string** TableOrders::select_single_order_for_client(const std::string &username, const std::string &cod_order, const string &us_prov)  {
    string query_user="SELECT id FROM users WHERE username ='"+username+"'";

    int id = db.execAndGet(query_user).getInt();

    string query_prov="SELECT id FROM users WHERE username ='"+us_prov+"'";

    int id_prov = db.execAndGet(query_prov).getInt();

    string** mat_client=new string *[select_count_single_order_for_client(username,cod_order,us_prov)];
    for (int k = 0; k < select_count_single_order_for_client(username,cod_order,us_prov); k++) {
        mat_client[k] = new string[3];
    }
    string select;
    int order=stoi(cod_order);
    select="SELECT quantity,price_product*quantity,desc_prod  FROM store, orders WHERE id_store=store.id AND orders.id_cust="+to_string(id)+" AND id_single_order="+
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
    string query_user="SELECT id FROM users WHERE username ='"+username+"'";

    int id = db.execAndGet(query_user).getInt();

    string query_prov="SELECT id FROM users WHERE username ='"+us_prov+"'";

    int id_prov = db.execAndGet(query_prov).getInt();

    int order=stoi(cod_order);

    string cancel="DELETE FROM orders WHERE id_single_order="+ to_string(order)+ " AND id_cust="+ to_string(id) +" AND id_prov="+to_string(id_prov)+"";
    cout << cancel;
    db.exec(cancel);

}
