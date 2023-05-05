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
    void add(const Favourites& fav);
    void remove_prod(int id);
    string** select(const string &username);
    int select_count(const string &username);


    private:
        Favourites data;
    };

#endif // INGROSSO_ONLINE_FAVOURITESMETHODS_H