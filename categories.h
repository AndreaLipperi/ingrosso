//
// Created by Matilde Tarchi on 29/07/22.
//

#ifndef INGROSSO_ONLINE_CATEGORIES_H
#define INGROSSO_ONLINE_CATEGORIES_H
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


#endif //INGROSSO_ONLINE_CATEGORIES_H