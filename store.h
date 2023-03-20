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
    Store(int new_quantity, Subcategories *new_prod, int new_price,const string &new_desc, const string &new_id_prov);

    int get_quantity() {
        return available_quantity;
    }
    Subcategories* get_prod() {
        return product;
    }

    int get_price() {
        return price_product;
    }

    string get_desc() {
        return description_prod;
    }
    string get_id_prov() {
        return IDprovider;
    }
    void set_quantity(int new_quantity){
        Store::available_quantity=new_quantity;
    }

    void set_desc(string new_desc){
        Store::description_prod=new_desc;
    }
    void set_price(int new_price){
        Store::price_product=new_price;
    }

private:
    int available_quantity;
    Subcategories *product;
    double price_product;
    string description_prod;
    string IDprovider;
};

#endif // INGROSSO_ONLINE_STORE_H