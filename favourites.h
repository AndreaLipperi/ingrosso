//
// Created by Matilde Tarchi on 29/07/22.
//

#ifndef INGR_ONLINE_CARRELLO_H
#define INGR_ONLINE_CARRELLO_H

#include "productsMethods.h"
#include "usersMethods.h"
#include <string>
using namespace std;
class Favourites : public TableUsers, public TableProducts{
public:

  Favourites();
  Favourites(int new_id, int new_quantity, int new_id_prod, string new_id_cust, string new_id_prov);
  int get_id() {
    return ID;
  }
  int get_quantity() {
    return quantity;
  }
  int get_id_prod(){
    return IDprod;
  }
  string get_id_cust(){
    return IDcustomer;
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
  void output(ostream& outs);
  void input(istream& ins);
  void set_name(int new_quantity){
    Favourites::quantity=new_quantity;
  }
  void set_IDprod(int new_id_prod){
    Favourites::IDprod=new_id_prod;
  }
  void set_IDuser(string new_id_cust){
    Favourites::IDcustomer=new_id_cust;
  }
  void set_IDprov(string new_id_prov){
    Favourites::IDprovider=new_id_prov;
  }

private :
  int ID;
  int quantity;
  int IDprod;
  string IDcustomer;
  string IDprovider;

};

ostream& operator<<(ostream& outs, Favourites& tmp) {
  tmp.output(outs);
  return outs;
}
istream& operator>>(istream& ins, Favourites& tmp) {
  tmp.input(ins);
  return ins;
}

#endif //INGR_ONLINE_CARRELLO_H
