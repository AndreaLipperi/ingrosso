//
// Created by Matilde Tarchi on 02/08/22.
//

#include "favourites.h"
#include <iostream>
#include <string>
using namespace std;


Favourites:: Favourites(const string &new_id_store, const string &new_cust, const string &new_prov) {
    id_store=new_id_store;
    username_cust=new_cust;
    username_prov=new_prov;
}

Favourites::Favourites() {

}
