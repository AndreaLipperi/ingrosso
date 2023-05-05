//
// Created by Andrea Lipperi on 16/11/22.
//

#include "orders.h"
#include <iostream>
#include <string>
using namespace std;

Orders::Orders() {

}
Orders::Orders(int new_quantity,int new_prod,const string &new_status, const string &new_date, const string &new_cust, const string &new_prov, int id_order){
    quantity=new_quantity;
    id_store=new_prod;
    username_cust=new_cust;
    status=new_status;
    date_order=new_date;
    username_prov=new_prov;
    IDorder=id_order;
}

