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
  Favourites(const string &new_id_store, const string &new_id_cust, const string &new_id_prov);

  string get_id_store(){
    return id_store;
  }
  string get_id_cust(){
    return IDcustomer;
  }
  string get_id_prov(){
    return IDprovider;
  }
  void set_id_store(string new_id_store){
    Favourites::id_store=new_id_store;
  }
  void set_IDuser(string new_id_cust){
    Favourites::IDcustomer=new_id_cust;
  }
  void set_IDprov(string new_id_prov){
    Favourites::IDprovider=new_id_prov;
  }

private :
  string id_store;
  string IDcustomer;
  string IDprovider;

};

#endif //INGROSSO_ONLINE_FAVOURITES_H
