//
// Created by Andrea Lipperi on 16/11/22.
//

#ifndef INGROSSO_DB_DB_STORE_H
#define INGROSSO_DB_DB_STORE_H
#include "subcategoriesMethods.h"
#include "usersMethods.h"
#include <string>
using namespace std;
class Store : public TableProducts, TableUsers {
public:
  Store();
  Store(int new_id,int new_quantity, Products *new_prod, int new_price,const string &new_desc, const string &new_id_prov);
  int get_id() {
    return ID;
  }
  int get_quantity() {
    return available_quantity;
  }
  Products* get_prod() {
    return product;
  }

  int get_price() {
    return price_product;
  }

  string get_desc() {
    return description_prod;
  }
  string get_id_prov() {
    return IDprovider;
  }
  string get_prov_name(string id_prov) {
    return TableUsers::select_username(id_prov);
  }
  void set_quantity(int new_quantity){
    Store::available_quantity=new_quantity;
  }

  void set_desc(string new_desc){
    Store::description_prod=new_desc;
  }
  void set_price(int new_price){
    Store::price_product=new_price;
  }

private:
  int ID;
  int available_quantity;
  Products *product;
  double price_product;
  string description_prod;
  string IDprovider;
};

#endif // INGROSSO_DB_DB_STORE_H
