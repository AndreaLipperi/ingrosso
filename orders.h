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
    Orders(int new_quantity, int new_prod,const string &new_status, const string &new_date, const string &new_cust, const string &new_prov, int id_order);

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
        return username_cust;
    }
    string get_id_prov(){
        return username_prov;
    }
    int get_id(){
        return IDorder;
    }
    void set_status(const string &new_status){
        Orders::status=new_status;
    }

private:
    int quantity;
    int id_store;
    string status;
    string date_order;
    string username_cust;
    string username_prov;
    int IDorder;
};

#endif // INGROSSO_ONLINE_ORDERS_H