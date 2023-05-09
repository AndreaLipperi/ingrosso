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
    void cancel_order(const std::string &username, const std::string &cod_order, const string &us_prov);
    int select_count(const string &username, int control);
    int select_count_for_client(const string &username, int control);
    int select_count_single_order(const string &username, const string &cod_order);
    int select_count_single_order_for_client(const string &username, const string &cod_order, const string &us_prov);
    string** select(const string &username, int control,const string &order="users.id");
    string** select_for_client(const string &username, int control, const string &order="users.id");
    int select_id(const string &username);
    string** select_single_order(const string &username, const string &cod_order);
    string** select_single_order_for_client(const string &username, const string &cod_order, const string &us_prov);
private:
    Orders data;
};
#endif // INGROSSO_ONLINE_ORDERSMETHODS_H