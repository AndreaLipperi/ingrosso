//
// Created by Andrea Lipperi on 08/05/23.
//

#ifndef INGROSSO_ONLINE_CITY_H
#define INGROSSO_ONLINE_CITY_H

#include "subcategoriesMethods.h"
#include "usersMethods.h"
#include "users.h"
#include "subcategories.h"
#include "store.h"
#include <string>
class City {
public:
    City();
    City(const string &new_city);

private:
    string city;
};


#endif //INGROSSO_ONLINE_CITY_H
