//
// Created by Andrea Lipperi on 14/11/22.
//

#include "store.h"
#include <iostream>
#include <string>
using namespace std;


Store::Store(const string &new_quantity, const string &new_prod, const string & new_price, const string &new_desc, const string &new_prov){

    available_quantity=new_quantity;
    sub=new_prod;
    price_product=new_price;
    description_prod=new_desc;
    username_prov=new_prov;
}

Store::Store() {

}
