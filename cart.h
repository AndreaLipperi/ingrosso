//
// Created by Matilde Tarchi on 29/07/22.
//

#ifndef INGR_ONLINE_MAGAZZINO_H
#define INGR_ONLINE_MAGAZZINO_H

#include "subcategoriesMethods.h"
#include "usersMethods.h"
#include "users.h"
#include "subcategories.h"
#include <string>
using namespace std;
class Cart : public TableUsers, public TableProducts{
public:
  Cart();
  Cart(int new_id, int new_quantity, Products *new_name_prod, const string &new_client, const string &new_prov);
  int get_id() {
    return ID;
  }
  int get_quantity() {
    return quantity;
  }
  Products* get_prod(){
    return prod;
  }
  string get_user(){
    return user;
  }
  string get_prov(){
    return provider;
  }
  string get_prod_name(const string &prod){
    return TableProducts::select_name(prod);
  }
  string get_prov_name(const string &prov) {
    return TableUsers::select_username(prov);
  }
  void set_quantity(int new_quantity){
    Cart::quantity=new_quantity;
  }
  void set_prod(Products *new_prod){
    Cart::prod=new_prod;
  }
  void set_IDuser(const string &new_user){
    Cart::user=new_user;
  }
void set_IDprov(const string &new_prov){
  Cart::provider=new_prov;
}

private:
    int ID;
    int quantity;
    Products *prod;
    string  user;
    string provider;
};

#endif //INGR_ONLINE_MAGAZZINO_H
