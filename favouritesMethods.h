//
// Created by Andrea Lipperi on 16/11/22.
//

#ifndef INGROSSO_ONLINE_FAVOURITESMETHODS_H
#define INGROSSO_ONLINE_FAVOURITESMETHODS_H
#include <string>
#include "favourites.h"
using namespace std;
class TableFavourites {
    public :
    TableFavourites();
    void add(const Favourites& cart);
    void remove_all(const string &IDuser);
    void remove_prod(Subcategories &prod, const string &IDuser);
    void changeData(const string &IDuser, Subcategories &prod, const string &new_IDprov, const int &new_quantity);
    void sort_id_prod();
    void sort_id_provider();
    private:
        Favourites data;
    };

#endif // INGROSSO_ONLINE_FAVOURITESMETHODS_H