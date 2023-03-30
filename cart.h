//
// Created by Matilde Tarchi on 29/07/22.
//


#ifndef INGROSSO_ONLINE_CART_H
#define INGROSSO_ONLINE_CART_H

#include "subcategoriesMethods.h"
#include "usersMethods.h"
#include "users.h"
#include "subcategories.h"
#include "store.h"
#include <string>
using namespace std;
class Cart {
public:
    Cart();
  Cart(int new_quantity,const string &new_id_store, const string &new_client, const string &new_prov);

  int get_quantity() {
    return quantity;
  }
    string get_id_store(){
        return id_store;
    }
  string get_id_user(){
    return IDuser;
  }
  string get_id_prov(){
    return IDprovider;
  }
  void set_quantity(int new_quantity){
    Cart::quantity=new_quantity;
  }
  void set_id_store(string new_id_store){
      Cart::id_store=new_id_store;
    }
  void set_IDuser(const string &new_id_user){
    Cart::IDuser=new_id_user;
  }
void set_IDprov(const string &new_id_prov){
  Cart::IDprovider=new_id_prov;
}

private:
    int quantity;
    string id_store;
    string IDuser;
    string IDprovider;
};

#endif //INGR_ONLINE_CART_H
