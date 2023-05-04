//
// Created by Andrea Lipperi on 16/11/22.
//


#include "storeMethods.h"
#include <SQLiteCpp/SQLiteCpp.h>
#include <SQLiteCpp/Statement.h>
#include <SQLiteCpp/Database.h>
#include "database.h"
#include <iostream>
#include <string>
using namespace std;

TableStore::TableStore() {
    string query = "CREATE TABLE IF NOT EXISTS store (id INTEGER PRIMARY KEY autoincrement, available_quantity INT NOT NULL,price_product DOUBLE NOT NULL, desc_prod VARCHAR NOT NULL, id_sub INT NOT NULL, id_prov INT NOT NULL,FOREIGN KEY(id_sub) REFERENCES subcategories (id), FOREIGN KEY (id_prov) REFERENCES users (id))";
    db.exec(query);
}


void TableStore::changeData(const int &id_store, const string &new_desc, const string &new_price, int new_quantity){
    string query="UPDATE store SET desc_prod = '"+ new_desc+"', price_product="+new_price+", available_quantity="+
                                                                                          to_string(new_quantity)+" WHERE id = "+
                 to_string(id_store)+"";
    db.exec(query);
}

void TableStore::add(const Store &store) {
    data=store;
    string query_sub="SELECT id FROM subcategories WHERE name='"+data.get_prod()+"'";
    int i=db.execAndGet(query_sub);
    string query_prov="SELECT id FROM users WHERE username = '"+data.get_id_prov()+"'";
    int k=db.execAndGet(query_prov).getInt();
    std::string query_id_inter="SELECT MAX(id_intern) FROM store WHERE id_prov="+ to_string(k)+"";
    int id_intern=db.execAndGet(query_id_inter).getInt();
    string query_insert="INSERT INTO store (available_quantity, price_product, desc_prod,id_sub, id_prov, id_intern) VALUES (" +
                        data.get_quantity() + ", " + data.get_price() + ", '"+data.get_desc()+"', "+
                                                                                                        to_string(i)+", "+
                                                                                                                     to_string(k)+", "+
                                                                                                                                  to_string(id_intern+1)+");";
    db.exec(query_insert);
}

int TableStore::remove(const int &id_store) {
    string query_count_in_fav="SELECT count(*) FROM favourites WHERE id_store="+ to_string(id_store)+"";
    int count_fav=db.execAndGet(query_count_in_fav);
    if (count_fav>0) {
        return 0;
    }
    string query_count_in_ord="SELECT count(*) FROM orders WHERE id_store="+ to_string(id_store)+" AND status='S'";
    int count_orders=db.execAndGet(query_count_in_ord);
    if (count_orders>0) {
        return 0;
    }
    string query_count_in_cart="SELECT count(*) FROM cart WHERE id_store="+ to_string(id_store)+"";
    int count_cart=db.execAndGet(query_count_in_cart);
    if (count_cart>0) {
        return 0;
    }
    string query="DELETE FROM store WHERE id = "+ to_string(id_store)+"";
    db.exec(query);
    return 1;
}

string** TableStore::select(const string &sub_name, const string &disp, const string &order) {


    string query_sub="SELECT id FROM subcategories WHERE name='"+sub_name+"'";
    int i = db.execAndGet(query_sub).getInt();
    string query_select_count="SELECT count(*) FROM store WHERE id_sub ="+ to_string(i)+"";
    int count = db.execAndGet(query_select_count).getInt();
    string** mat=new string *[count];
    for (int k = 0; k < count; k++) {
        mat[k] = new string[5];
    }
    string select;
    int n_disp;
    if (disp=="Only Available") {
        n_disp=1;
    } else {
        n_disp=0;
    }
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

    string query_sub="SELECT id FROM subcategories WHERE name='"+sub_name+"'";
    int i = db.execAndGet(query_sub).getInt();
    int n_disp;
    if (disp=="Only Available") {
        n_disp=1;
    } else {
        n_disp=0;
    }
    string query_select_count="SELECT count(*) FROM store WHERE id_sub ="+ to_string(i)+" AND available_quantity>="+to_string(n_disp)+"";
    int count = db.execAndGet(query_select_count).getInt();
    return count;
}

string** TableStore::select_for_prov(const string &username, const string &order) {
    string query_select_prov="SELECT id FROM users WHERE username='"+username+"'";
    int id_prov=db.execAndGet(query_select_prov).getInt();
    string query_select_count="SELECT count(*) FROM store WHERE id_prov ="+ to_string(id_prov)+"";
    int count = db.execAndGet(query_select_count).getInt();
    string** mat=new string *[count];
    for (int k = 0; k < count; k++) {
        mat[k] = new string[4];
    }
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

    string query_user="SELECT id FROM users WHERE username='"+username+"'";
    int i = db.execAndGet(query_user).getInt();
    string query_select_count="SELECT count(*) FROM store WHERE id_prov ="+ to_string(i)+"";
    int count = db.execAndGet(query_select_count).getInt();
    return count;
}
string** TableStore::select_to_modify(int id_store) {
    string** mat=new string *[1];
    for (int k = 0; k < 1; k++) {
        mat[k] = new string[3];
    }
    string select;
    select="SELECT desc_prod, price_product, available_quantity FROM store WHERE id="+ to_string(id_store)+";";
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