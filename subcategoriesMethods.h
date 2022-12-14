//
// Created by Andrea Lipperi on 16/11/22.
//

#ifndef INGROSSO_DB_DB_SUBCATEGORIESMETHODS_H
#define INGROSSO_DB_DB_SUBCATEGORIESMETHODS_H

#include "subcategories.h"
#include <string>
class TableProducts {
public :
    TableProducts();
    ~TableProducts();
    TableProducts(const TableProducts& other);
    void operator =(const TableProducts& other);
    void add(const Products& prod);
    string select_name(const string &name);
    void remove(const string &name);
    void changeData(const string &name);
    void sort_id();
private:
    void make_bigger();
    int capacity;
    Products *data;
    int used;
};

#endif // INGROSSO_DB_DB_SUBCATEGORIESMETHODS_H