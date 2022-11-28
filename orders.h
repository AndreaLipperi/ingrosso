//
// Created by Andrea Lipperi on 16/11/22.
//

#ifndef INGROSSO_DB_DB_ORDERS_H
#define INGROSSO_DB_DB_ORDERS_H

#include "subcategoriesMethods.h"
#include "usersMethods.h"
#include <string>
using namespace std;
class Orders: public TableUsers, public TableProducts{
public:
  Orders();
  Orders(int new_id, int new_quantity, Products *new_prod,const string &new_status, const string &new_date, const string &new_id_cust, const string &new_id_prov);
  int get_id() {
    return ID;
  }
  int get_quantity() {
    return quantity;
  }
  Products* get_prod(){
    return prod;
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
  string get_cust_name(const string &id_cust) {
    return TableUsers::select_username(id_cust);
  }
  string get_prov_name(const string &id_prov) {
    return TableUsers::select_username(id_prov);
  }
  void set_status(const string &new_status){
    Orders::status=new_status;
  }

private:
  int ID;
  int quantity;
  Products *prod;
  string status;
  string date_order;
  string IDcust;
  string IDprovider;
};

#endif // INGROSSO_DB_DB_ORDERS_H
