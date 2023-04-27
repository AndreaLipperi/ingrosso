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
    void changeStatus(const string& username,const string &cod_order,const string &new_status);
    int select_count(const string &username);
    int select_count_single_order(const string &username, const string &cod_order);
    string** select(const string &username,const string &order="id");
    int select_id(const string &username);
    string** select_single_order(const string &username, const string &cod_order);
private:
    Orders data;
};
#endif // INGROSSO_ONLINE_ORDERSMETHODS_H