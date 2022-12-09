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
}

Favourites:: Favourites(int new_id, int new_quantity, Products *new_prod, const string &new_id_cust, const string &new_id_prov) : prod(new_prod) {
    ID = new_id;
    quantity= new_quantity;
    IDcustomer=new_id_cust;
    IDprovider=new_id_prov;
}