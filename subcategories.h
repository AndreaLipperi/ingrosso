//
// Created by Matilde Tarchi on 29/07/22.
//

#ifndef INGR_ONLINE_PRODOTTI_H
#define INGR_ONLINE_PRODOTTI_H
#include "categoriesMethods.h"
#include <string>
using namespace std;
class Products : public TableCategories {
public:
  Products();
  Products(int new_id,std::string new_name, int new_id_cat);
  int get_id() {
    return ID;
  }
  string get_name() {
    return name;
  }
  int get_id_cat(){
    return IDcat;
  }

  string get_cat_name(int id_cat){
    return TableCategories::select_name(id_cat);
  }
  void set_name(string new_name){
    Products::name=new_name;
  }
  void set_IDcat(int new_id_cat){
    Products::IDcat=new_id_cat;
  }
private:
  int ID;
  string name;
  int IDcat;
};

#endif //INGR_ONLINE_PRODOTTI_H
