//
// Created by Matilde Tarchi on 02/08/22.
//

#include "cart.h"
#include <iostream>
#include <string>
using namespace std;

Cart::Cart() {
    ID=0;
    quantity=0;
}

Cart::Cart(int new_id, int new_quantity, Products *new_name_prod,  const string &new_id_user,  const string &new_id_prov) : prod(new_name_prod) {
    ID = new_id;
    quantity= new_quantity;
    user=new_id_user;
    provider=new_id_prov;
}