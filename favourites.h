//
// Created by Matilde Tarchi on 29/07/22.
//

#ifndef INGROSSO_ONLINE_FAVOURITES_H
#define INGROSSO_ONLINE_FAVOURITES_H

#include "subcategoriesMethods.h"
#include "usersMethods.h"
#include <string>
using namespace std;
class Favourites{
public:
Favourites();
  Favourites(int new_id, int new_quantity, Subcategories *new_prod, const string &new_id_cust, const string &new_id_prov);
  int get_id() {
    return ID;
  }
  int get_quantity() {
    return quantity;
  }
    Subcategories* get_prod(){
    return prod;
  }
  string get_id_cust(){
    return IDcustomer;
  }
  string get_id_prov(){
    return IDprovider;
  }
  void set_name(int new_quantity){
    Favourites::quantity=new_quantity;
  }
  void set_prod(Subcategories *new_prod){
    Favourites::prod=new_prod;
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
  Subcategories *prod;
  string IDcustomer;
  string IDprovider;

};

#endif //INGROSSO_ONLINE_FAVOURITES_H
