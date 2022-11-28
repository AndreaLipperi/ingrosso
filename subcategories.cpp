//
// Created by Andrea Lipperi on 14/11/22.
//

#include "subcategories.h"
#include <iostream>
#include <string>
using namespace std;
Products::Products(const std::string &new_name, Categories *new_cat) : cat(new_cat) {
  name= new_name;
}
