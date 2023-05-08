//
// Created by Andrea Lipperi on 16/11/22.
//

#ifndef INGROSSO_ONLINE_STORE_H
#define INGROSSO_ONLINE_STORE_H
#include "subcategoriesMethods.h"
#include "usersMethods.h"
#include <string>
using namespace std;
class Store{
public:
    Store();
    Store(const string &new_quantity,const string &new_prod, const string &new_price,const string &new_desc, const string &new_prov);

    string get_quantity() {
        return available_quantity;
    }
    string get_prod() {
        return sub;
    }

    string get_price() {
        return price_product;
    }

    string get_desc() {
        return description_prod;
    }
    string get_id_prov() {
        return username_prov;
    }
    void set_quantity(string new_quantity){
        Store::available_quantity=new_quantity;
    }

    void set_desc(string new_desc){
        Store::description_prod=new_desc;
    }
    void set_price(string new_price){
        Store::price_product=new_price;
    }

private:
    string available_quantity;
    string sub;
    string price_product;
    string description_prod;
    string username_prov;
};

#endif // INGROSSO_ONLINE_STORE_H