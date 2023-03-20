//
// Created by Matilde Tarchi on 02/08/22.
//

#include "cart.h"
#include "subcategories.h"
#include <iostream>
#include <string>
using namespace std;


Cart::Cart(int new_quantity, Subcategories *new_name_prod,  const string &new_id_user,  const string &new_id_prov) : prod(new_name_prod) {

  quantity= new_quantity;
  IDuser=new_id_user;
  IDprovider=new_id_prov;
}

Cart::Cart() {

}
