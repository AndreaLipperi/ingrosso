//
// Created by Matilde Tarchi on 29/07/22.
//

#ifndef INGR_ONLINE_CATEGORIE_H
#define INGR_ONLINE_CATEGORIE_H
#include <string>
using namespace std;
class Categories {

  Categories();
    Categories(int new_id,std::string new_name);
    int get_id() {
      return ID;
    }
    string get_name() {
      return name;
    }
    void output(ostream& outs);
    void input(istream& ins);
    void set_name(string new_name){
      Categories::name=new_name;
    }
  private:
    int ID;
    string name;
};


#endif //INGR_ONLINE_CATEGORIE_H
