//
// Created by Andrea Lipperi on 16/11/22.
//

#include "orders.h"
#include <iostream>
#include <string>
using namespace std;
Orders::Orders() {
  ID=0;
  IDprod=0;
  quantity=0;
}
Orders::Orders(int new_id, int new_quantity, int new_id_prod,string new_status, string new_date, string new_id_cust, string new_id_prov) {
  ID=new_id;
  quantity=new_quantity;
  IDprod=new_id_prod;
  IDcust=new_id_cust;
  status=new_status;
  date_order=new_date;
  IDprovider=new_id_prov;
}
