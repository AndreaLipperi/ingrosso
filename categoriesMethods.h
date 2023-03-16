//
// Created by Andrea Lipperi on 16/11/22.
//

#ifndef INGROSSO_ONLINE_CATEGORIESMETHODS_H
#define INGROSSO_ONLINE_CATEGORIESMETHODS_H

#include <string>
#include "categories.h"
using namespace std;
class TableCategories {
public :
    TableCategories();
    int add(const Categories& cat);
    void remove(const string &name);
    string* select_all();
    string select_name(const string &name);
    void changeName(const string &name, const string &new_name);
    void sort_name();
private:
    Categories data;
};

#endif // INGROSSO_ONLINE_CATEGORIESMETHODS_H