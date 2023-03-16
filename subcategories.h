//
// Created by Andrea Lipperi on 16/03/23.
//

#ifndef INGROSSO_ONLINE_SUBCATEGORIES_H
#define INGROSSO_ONLINE_SUBCATEGORIES_H

#include "categoriesMethods.h"
#include <string>
using namespace std;
class Products : public TableCategories {
public:
    Products();
    Products(const std::string &new_name, Categories *new_cat);
    string get_name() {
        return name;
    }
    Categories* get_cat(){
        return cat;
    }

    void set_name(const string &new_name){
        Products::name=new_name;
    }
    void set_cat(Categories *new_cat){
        Products::cat=new_cat;
    }
private:
    string name;
    Categories *cat;
};

#endif //INGROSSO_ONLINE_SUBCATEGORIES_H
