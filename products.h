//
// Created by Matilde Tarchi on 29/07/22.
//

#ifndef INGR_ONLINE_PRODOTTI_H
#define INGR_ONLINE_PRODOTTI_H
#include <string>
#include "tableCategories.h"
using namespace std;
class Products : public TableCategories {
public:
  Products();
  Products(int new_id,std::string new_name, string new_description, int new_id_cat);
  int get_id() {
    return ID;
  }
  string get_name() {
    return name;
  }
  string get_description(){
    return description;
  }
  int get_id_cat(){
    return IDcat;
  }

  string get_cat_name(int id_cat){
    return TableCategories::select_name(id_cat);
  }
  void output(ostream& outs);
  void input(istream& ins);
  void set_name(string new_name){
    Products::name=new_name;
  }
  void set_description(string new_desc){
    Products::description=new_desc;
  }
  void set_IDcat(int new_id_cat){
    Products::IDcat=new_id_cat;
  }
private:
  int ID;
  string name;
  string description;
  int IDcat;
};
ostream& operator<<(ostream& outs, Products& tmp) {
  tmp.output(outs);
  return outs;
}
istream& operator>>(istream& ins, Products& tmp) {
  tmp.input(ins);
  return ins;
}


#endif //INGR_ONLINE_PRODOTTI_H
