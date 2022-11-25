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
  IDprod=0;
}

Cart::Cart(int new_id, int new_quantity, int new_id_prod, string new_id_user, string new_id_prov) {
  ID = new_id;
  quantity= new_quantity;
  IDprod=new_id_prod;
  IDuser=new_id_user;
  IDprovider=new_id_prov;
}
