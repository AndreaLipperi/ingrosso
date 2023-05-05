//
// Created by Andrea Lipperi on 16/11/22.
//

#ifndef INGROSSO_ONLINE_CATEGORIESMETHODS_H
#define INGROSSO_ONLINE_CATEGORIESMETHODS_H

#include <string>
#include <vector>
#include "categories.h"
using namespace std;
class TableCategories {
public :
    TableCategories();
    int number_of_cat();
    std::vector<std::string> select();
private:
    Categories data;
};

#endif // INGROSSO_ONLINE_CATEGORIESMETHODS_H