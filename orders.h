//
// Created by Andrea Lipperi on 16/11/22.
//

#ifndef INGROSSO_DB_DB_ORDERS_H
#define INGROSSO_DB_DB_ORDERS_H

#include "productsMethods.h"
#include "usersMethods.h"
#include <string>
using namespace std;
class Orders: public TableUsers, public TableProducts{
public:
  Orders();
  Orders(int new_id, int new_quantity, int new_id_prod,string new_status, string new_date, string new_id_cust, string new_id_prov);
  int get_id() {
    return ID;
  }
  int get_quantity() {
    return quantity;
  }
  int get_id_prod(){
    return IDprod;
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
  string get_prod_name(int id_prod){
    return TableProducts::select_name(id_prod);
  }
  string get_cust_name(string id_cust) {
    return TableUsers::select_username(id_cust);
  }
  string get_prov_name(string id_prov) {
    return TableUsers::select_username(id_prov);
  }
  void output(ostream& outs);
  void input(istream& ins);
  void set_status(string new_status){
    Orders::status=new_status;
  }

private:
  int ID;
  int quantity;
  int IDprod;
  string status;
  string date_order;
  string IDcust;
  string IDprovider;
};

ostream& operator<<(ostream& outs, Orders& tmp) {
  tmp.output(outs);
  return outs;
}
istream& operator>>(istream& ins, Orders& tmp) {
  tmp.input(ins);
  return ins;
}
#endif // INGROSSO_DB_DB_ORDERS_H
