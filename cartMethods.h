//
// Created by Andrea Lipperi on 16/11/22.
//

#ifndef INGROSSO_ONLINE_CARTMETHODS_H
#define INGROSSO_ONLINE_CARTMETHODS_H

#include <string>
#include "cart.h"
#include "subcategories.h"
using namespace std;
class TableCart {
public :
    TableCart();
    void add(const Cart& cart);
    void remove_all(const string &IDuser);
    void remove_prod(Products &prod, const string &IDuser);
    void changeData(const string &IDuser, Products &prod, const string &new_IDprov, const int &new_quantity);
    void sort_id_prod();
    void sort_id_provider();
private:
    Cart data;
};

#endif // INGROSSO_ONLINE_CARTMETHODS_H