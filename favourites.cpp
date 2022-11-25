//
// Created by Matilde Tarchi on 02/08/22.
//

#include "favourites.h"
#include <iostream>
#include <string>
using namespace std;

Favourites::Favourites() {
  ID=0;
  quantity=0;
  IDprod=0;
}

Favourites::Favourites(int new_id, int new_quantity, int new_id_prod, string new_id_cust, string new_id_prov) {
  ID = new_id;
  quantity= new_quantity;
  IDprod=new_id_prod;
  IDcustomer=new_id_cust;
  IDprovider=new_id_prov;
}
