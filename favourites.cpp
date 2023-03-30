//
// Created by Matilde Tarchi on 02/08/22.
//

#include "favourites.h"
#include <iostream>
#include <string>
using namespace std;


Favourites:: Favourites(const string &new_id_store, const string &new_id_cust, const string &new_id_prov) {
    id_store=new_id_store;
    IDcustomer=new_id_cust;
    IDprovider=new_id_prov;
}

Favourites::Favourites() {

}
