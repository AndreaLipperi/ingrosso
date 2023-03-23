//
// Created by Andrea Lipperi on 16/11/22.
//

#ifndef INGROSSO_ONLINE_STOREMETHODS_H
#define INGROSSO_ONLINE_STOREMETHODS_H


#include <string>
#include "store.h"
using namespace std;
class TableStore {
public :
    TableStore();
    void add(const Store& store);
    void remove(const int &id_inter, const string &id_prov);
    void changeQuantity(const int &id_inter, const string &id_prov,const int &new_quantity);
    void changeDesc(const int &id_inter, const string &id_prov, const string &new_desc);
    string** select(Subcategories &sub);
private:
    Store data;
};

#endif // INGROSSO_ONLINE_STOREMETHODS_H