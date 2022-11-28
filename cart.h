//
// Created by Matilde Tarchi on 29/07/22.
//

#ifndef INGR_ONLINE_MAGAZZINO_H
#define INGR_ONLINE_MAGAZZINO_H

#include "subcategoriesMethods.h"
#include "usersMethods.h"
#include <string>
using namespace std;
class Cart : public TableUsers, public TableProducts{
public:
  Cart();
  Cart(int new_id, int new_quantity, int new_id_prod, const string &new_id_user, string new_id_prov);
  int get_id() {
    return ID;
  }
  int get_quantity() {
    return quantity;
  }
  int get_id_prod(){
    return IDprod;
  }
  string get_id_user(){
    return IDuser;
  }
  string get_id_prov(){
    return IDprovider;
  }
  string get_prod_name(int id_prod){
    return TableProducts::select_name(id_prod);
  }
  string get_prov_name(string id_prov) {
    return TableUsers::select_username(id_prov);
  }
  void set_quantity(int new_quantity){
    Cart::quantity=new_quantity;
  }
  void set_IDprod(int new_id_prod){
    Cart::IDprod=new_id_prod;
  }
  void set_IDuser(string new_id_user){
    Cart::IDuser=new_id_user;
  }
void set_IDprov(string new_id_prov){
  Cart::IDprovider=new_id_prov;
}

private:
    int ID;
    int quantity;
    int IDprod;
    string IDuser;
    string IDprovider;
};

#endif //INGR_ONLINE_MAGAZZINO_H
