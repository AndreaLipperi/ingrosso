//
// Created by Andrea Lipperi on 16/03/23.
//

#ifndef INGROSSO_ONLINE_SUBCATEGORIES_H
#define INGROSSO_ONLINE_SUBCATEGORIES_H

#include "categoriesMethods.h"
#include <string>
using namespace std;
class Subcategories{
public:
    Subcategories();
    Subcategories(const std::string &new_name, Categories *new_cat);
    string get_name() {
        return name;
    }
    Categories* get_cat(){
        return cat;
    }

    void set_name(const string &new_name){
        Subcategories::name=new_name;
    }
    void set_cat(Categories *new_cat){
        Subcategories::cat=new_cat;
    }
private:
    string name;
    Categories *cat;
};

#endif //INGROSSO_ONLINE_SUBCATEGORIES_H
