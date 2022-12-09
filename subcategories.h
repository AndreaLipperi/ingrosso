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

#endif //INGR_ONLINE_PRODOTTI_H