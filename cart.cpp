//
// Created by Matilde Tarchi on 02/08/22.
//

#include "cart.h"
#include "subcategories.h"
#include <iostream>
#include <string>
using namespace std;


Cart::Cart(int new_quantity, const string &new_id_store,  const string &new_id_user,  const string &new_id_prov) {
    id_store=new_id_store;
  quantity= new_quantity;
  IDuser=new_id_user;
  IDprovider=new_id_prov;
}

Cart::Cart() {

}
