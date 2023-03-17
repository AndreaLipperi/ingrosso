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
    ~TableStore();
    TableStore(const TableStore& other);
    void operator =(const TableStore& other);
    void add(const Store& store);
    void remove(int id);
    void changeQuantity(Subcategories *prod, const string &id_prov);
    void changeDesc(Subcategories *prod, const string &id_prov);
    void save(ostream& outs);
    void load(istream& ins);
private:
    void make_bigger();
    int capacity;
    Store *data;
    int used;
};

#endif // INGROSSO_ONLINE_STOREMETHODS_H