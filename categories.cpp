//
// Created by Andrea Lipperi on 14/11/22.
//

#include "categories.h"
#include <iostream>
#include <string>
using namespace std;

Categories::Categories() {
  ID=0;
}

Categories::Categories(int new_id,std::string new_name) {
  ID = new_id;
  name= new_name;
}
