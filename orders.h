//
// Created by Andrea Lipperi on 16/11/22.
//

#ifndef INGROSSO_ONLINE_ORDERS_H
#define INGROSSO_ONLINE_ORDERS_H

#include "subcategoriesMethods.h"
#include "usersMethods.h"
#include "storeMethods.h"

#include <string>
using namespace std;
class Orders{
public:
    Orders();
    Orders(int new_quantity, int new_prod,const string &new_status, const string &new_date, const string &new_id_cust, const string &new_id_prov);

    int get_quantity() {
        return quantity;
    }
    int get_prod(){
        return id_store;
    }
    string get_status(){
        return status;
    }
    string get_date(){
        return date_order;
    }
    string get_id_cust(){
        return IDcust;
    }
    string get_id_prov(){
        return IDprovider;
    }
    void set_status(const string &new_status){
        Orders::status=new_status;
    }

private:
    int quantity;
    int id_store;
    string status;
    string date_order;
    string IDcust;
    string IDprovider;
};

#endif // INGROSSO_ONLINE_ORDERS_H