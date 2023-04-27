//
// Created by Andrea Lipperi on 16/11/22.
//

#ifndef INGROSSO_ONLINE_CARTMETHODS_H
#define INGROSSO_ONLINE_CARTMETHODS_H

#include <string>
#include "cart.h"
#include "subcategories.h"
#include "store.h"
using namespace std;
class TableCart {
public :
    TableCart();
    void add(const Cart& cart);
    void remove_all(const string &username);
    void remove_prod(int id);
    void changeData(const string &IDuser, Store &prod, const string &new_IDprov, const int &new_quantity);
    int select_count(const string &username);
    string** select(const string &username);
private:
    Cart data;
};

#endif // INGROSSO_ONLINE_CARTMETHODS_H