//
// Created by Matilde Tarchi on 29/07/22.
//

#ifndef INGR_ONLINE_CATEGORIE_H
#define INGR_ONLINE_CATEGORIE_H
#include <string>
using namespace std;
class Categories {
public:
    Categories();
    Categories(const std::string &new_name);
    string get_name() {
        return name;
    }
    void set_name(const string &new_name){
        Categories::name=new_name;
    }
private:
    string name;
};


#endif //INGR_ONLINE_CATEGORIE_H