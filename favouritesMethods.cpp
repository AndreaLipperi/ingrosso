///
// Created by Andrea Lipperi on 16/11/22.
//

#include "favouritesMethods.h"
#include <SQLiteCpp/SQLiteCpp.h>
#include <SQLiteCpp/Statement.h>
#include <SQLiteCpp/Database.h>
#include <iostream>
#include <string>
using namespace std;

TableFavourites::TableFavourites() {
    used = 0;
    capacity = 5;
    data = new Favourites[capacity];
}
TableFavourites::~TableFavourites() {
    delete []data;
}


void TableFavourites::add(const Favourites& fav) {
    if (used>=capacity) {
        make_bigger();
    }
    data[used]= fav;
    used++;
}
void TableFavourites::remove_prod(Subcategories *prod, const string &IDcust) {
    for (int i=0; i<used; i++) {
        if (data[i].get_prod() == prod && data[i].get_id_cust()==IDcust) {

            used++;
        }
    }
}
void TableFavourites::sort_id_provider() {
    bool done = false;
    Favourites tmp;
    while(!done) {
        done = true;
        for(int i=0; i<used; i++) {
            if (data[i].get_id_prov() > data[i+1].get_id_prov()) {
                done = false;
            }
        }
    }
}
void TableFavourites::changeData(const string &IDcust, Subcategories *prod) {
    int num_result = 0;
    int save;
    for (int i=0; i<used; i++) {
        if (data[i].get_prod() == prod && data[i].get_id_cust()==IDcust) {
            num_result++;
            save=i;
            i=used;
        }
    }
    if (num_result>0) {
        int new_quantity;
        string new_provider;
        cout << "Enter new quantity: ";
        cin >> new_quantity;
        data[save].set_name(new_quantity);
        cout << "enter provider business name: ";
        cin >> new_provider;
        data[save].set_IDprov(new_provider);
    }
}