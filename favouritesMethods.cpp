//
// Created by Andrea Lipperi on 16/11/22.
//

#include "favouritesMethods.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

TableFavourites::TableFavourites() {
  used = 0;
  capacity = 5;
  data = new Favourites[capacity];
}
TableFavourites::TableFavourites(const TableFavourites &other) {
  used = other.used;
  capacity = other.capacity;
  data = new Favourites[capacity];
  copy(other.data, other.data+used, data);
}
TableFavourites::~TableFavourites() {
  delete []data;
}

void TableFavourites::operator=(const TableFavourites &other) {
  if (&other == this) {
    return;
  }
  delete []data;
  capacity = other.capacity;
  used = other.used;
  data = new Favourites[capacity];
  copy(other.data, other.data+used, data);
}
void TableFavourites::make_bigger() {
  Favourites *tmp;
  tmp = new Favourites[capacity + 5];
  copy(data, data+used,tmp);
  delete []data;
  data = tmp;
  capacity +=5;
}
void TableFavourites::add(const Favourites& fav) {
  if (used>=capacity) {
    make_bigger();
  }
  data[used]= fav;
  used++;
}
void TableFavourites::remove_prod(int IDprod, string IDcust) {
  for (int i=0; i<used; i++) {
    if (data[i].get_id_prod() == IDprod && data[i].get_id_cust()==IDcust) {
      data[i] = data[used-1];
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
        tmp = data[i];
        data[i] = data[i+1];
        data[i+1] = tmp;
      }
    }
  }
}
void TableFavourites::changeData(string IDcust, int IDprod) {
  int num_result = 0;
  int save;
  for (int i=0; i<used; i++) {
    if (data[i].get_id_prod() == IDprod && data[i].get_id_cust()==IDcust) {
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