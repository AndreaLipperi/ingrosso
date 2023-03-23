//
// Created by Andrea Lipperi on 16/11/22.
//

#ifndef INGROSSO_ONLINE_ORDERSMETHODS_H
#define INGROSSO_ONLINE_ORDERSMETHODS_H

#include <string>
#include "orders.h"
using namespace std;
class TableOrders {
public :
    TableOrders();
    void add(const Orders& order);
    void changeStatus(const string &IDuser, const string &new_IDprov, const string &new_status);

private:
    Orders data;
};
#endif // INGROSSO_ONLINE_ORDERSMETHODS_H