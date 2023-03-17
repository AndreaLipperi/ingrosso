//
// Created by Andrea Lipperi on 16/03/23.
//

#include "subcategories.h"
#include <iostream>
#include <string>
using namespace std;
Subcategories::Subcategories(const std::string &new_name, Categories *new_cat) : cat(new_cat) {
    name= new_name;
}

Subcategories::Subcategories() {

}
