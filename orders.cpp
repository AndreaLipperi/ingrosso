//
// Created by Andrea Lipperi on 16/11/22.
//

#include "orders.h"
#include <iostream>
#include <string>
using namespace std;
Orders::Orders() {
  ID=0;
  quantity=0;
}
Orders::Orders(int new_id, int new_quantity, Products *new_prod,const string &new_status, const string &new_date, const string &new_id_cust, const string &new_id_prov) : prod(new_prod) {
  ID=new_id;
  quantity=new_quantity;
  IDcust=new_id_cust;
  status=new_status;
  date_order=new_date;
  IDprovider=new_id_prov;
}
