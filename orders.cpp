//
// Created by Andrea Lipperi on 16/11/22.
//

#include "orders.h"
#include <iostream>
#include <string>
using namespace std;

Orders::Orders() {

}
Orders::Orders(int new_quantity,int new_prod,const string &new_status, const string &new_date, const string &new_id_cust, const string &new_id_prov){
    quantity=new_quantity;
    id_store=new_prod;
    IDcust=new_id_cust;
    status=new_status;
    date_order=new_date;
    IDprovider=new_id_prov;
}

