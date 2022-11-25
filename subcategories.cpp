//
// Created by Andrea Lipperi on 14/11/22.
//

#include "subcategories.h"
#include <iostream>
#include <string>
using namespace std;

Products::Products() {
  ID=0;
  IDcat=0;
}

Products::Products(int new_id, std::string new_name, int new_id_cat) {
  ID = new_id;
  name= new_name;
  IDcat=new_id_cat;
}
