//
// Created by Andrea Lipperi on 16/11/22.
//

#include "orders.h"
#include <iostream>
#include <string>
using namespace std;
Orders::Orders(int new_quantity, Store *new_prod,const string &new_status, const string &new_date, const string &new_id_cust, const string &new_id_prov) : store(new_prod) {
    quantity=new_quantity;
    IDcust=new_id_cust;
    status=new_status;
    date_order=new_date;
    IDprovider=new_id_prov;
}

Orders::Orders() {

}
