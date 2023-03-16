//
// Created by Andrea Lipperi on 16/11/22.
//

#ifndef INGROSSO_ONLINE_FAVOURITESMETHODS_H
#define INGROSSO_ONLINE_FAVOURITESMETHODS_H
#include <string>
#include "favourites.h"
using namespace std;
class TableFavourites {
    TableFavourites();
    ~TableFavourites();
    TableFavourites(const TableFavourites& other);
    void operator =(const TableFavourites& other);
    void add(const Favourites& fav);
    void remove_prod(Products *prod, const string &IDcust);
    void changeData(const string &IDcust, Products *prod);
    void sort_id_prod();
    void sort_id_provider();
private:
    void make_bigger();
    int capacity;
    Favourites *data;
    int used;
};

#endif // INGROSSO_ONLINE_FAVOURITESMETHODS_H