//
// Created by Andrea Lipperi on 16/11/22.
//

#ifndef INGROSSO_DB_DB_TABELCATEGORIES_H
#define INGROSSO_DB_DB_TABELCATEGORIES_H

#include <string>
#include "categories.h"
using namespace std;
class TableCategories {
public :
    TableCategories();
    int add(const Categories& cat);
    void remove(const string &name);
    string select_name(const string &name);
    void changeName(const string &name, const string &new_name);
    void sort_name();
private:
    Categories data;
};

#endif // INGROSSO_DB_DB_TABELCATEGORIES_H