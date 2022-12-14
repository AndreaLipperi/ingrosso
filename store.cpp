//
// Created by Andrea Lipperi on 14/11/22.
//

#include "store.h"
#include <iostream>
#include <string>
using namespace std;

Store::Store() {
    ID=0;
    available_quantity=0;
    price_product=0;
}

Store::Store(int new_id,int new_quantity, Products *new_prod, int new_price, const string &new_desc, const string &new_id_prov) : product(new_prod){
    ID = new_id;
    available_quantity=new_quantity;
    price_product=new_price;
    description_prod=new_desc;
    IDprovider=new_id_prov;
}