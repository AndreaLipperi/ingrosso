//
// Created by Andrea Lipperi on 08/05/23.
//

#ifndef INGROSSO_ONLINE_CITYMETHODS_H
#define INGROSSO_ONLINE_CITYMETHODS_H


#include <string>
#include "city.h"
#include <vector>
class TableCity {
public :
    TableCity();
    int number_of_city();
    std::vector<std::string> select();
private:
    City data;
};


#endif //INGROSSO_ONLINE_CITYMETHODS_H
