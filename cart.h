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
  string get_id_user(){
    return IDuser;
  }
  string get_id_prov(){
    return IDprovider;
  }
  string get_prod_name(const string& prod){
    return TableProducts::select_name(prod);
  }
  string get_prov_name(const string &id_prov) {
    return TableUsers::select_username(id_prov);
  }
  void set_quantity(int new_quantity){
    Cart::quantity=new_quantity;
  }
  void set_prod(Products *new_prod){
    Cart::prod=new_prod;
  }
  void set_IDuser(const string &new_id_user){
    Cart::IDuser=new_id_user;
  }
void set_IDprov(const string &new_id_prov){
  Cart::IDprovider=new_id_prov;
}

private:
    int ID;
    int quantity;
    Products *prod;
    string IDuser;
    string IDprovider;
};

#endif //INGR_ONLINE_MAGAZZINO_H
