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
    int remove(const int &id_store);
    void changeData(const int &id_store, const string &new_desc, const string &new_price, int new_quantity);
    string** select_to_modify(int id_store);
    string** select(const string &sub_name, const string &disp, const string &order="id");
    string** select_for_prov(const string &username, const string &order="id");
    int select_count(const string &sub_name, const string &disp);
    int select_count_for_prov(const string &username);
private:
    Store data;
};

#endif // INGROSSO_ONLINE_STOREMETHODS_H