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
    std::vector<std::string> select(const string &categories_name);
private:
    Subcategories data;
};

#endif // INGROSSO_ONLINE_SUBCATEGORIESMETHODS_H