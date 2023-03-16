//
// Created by Andrea Lipperi on 16/11/22.
//

#ifndef INGROSSO_ONLINE_SUBCATEGORIESMETHODS_H
#define INGROSSO_ONLINE_SUBCATEGORIESMETHODS_H

#include "subcategories.h"
#include <string>
class TableProducts {
public :
    TableProducts();
    void add(const Products& prod);
    string select_name(const string &name);
    void remove(const string &name);
    void changeData(const string &name, const string &new_name);
    void sort_id();
private:
    Products data;
};

#endif // INGROSSO_ONLINE_SUBCATEGORIESMETHODS_H