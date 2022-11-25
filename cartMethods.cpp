//
// Created by Andrea Lipperi on 14/11/22.
//

#include "cartMethods.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

TableCart::TableCart() {
  used = 0;
  capacity = 5;
  data = new Cart[capacity];
}
TableCart::TableCart(const TableCart &other) {
  used = other.used;
  capacity = other.capacity;
  data = new Cart[capacity];
  copy(other.data, other.data+used, data);
}
TableCart::~TableCart() {
  delete []data;
}

void TableCart::operator=(const TableCart &other) {
  if (&other == this) {
    return;
  }
  delete []data;
  capacity = other.capacity;
  used = other.used;
  data = new Cart[capacity];
  copy(other.data, other.data+used, data);
}
void TableCart::make_bigger() {
  Cart *tmp;
  tmp = new Cart[capacity + 5];
  copy(data, data+used,tmp);
  delete []data;
  data = tmp;
  capacity +=5;
}
void TableCart::add(const Cart& cart) {
  if (used>=capacity) {
    make_bigger();
  }
  data[used]= cart;
  used++;
}
void TableCart::remove_all(string IDuser) {
  for (int i=0; i<used; i++) {
    if (data[i].get_id_user() == IDuser) {
      data[i] = data[used-1];
      used++;
    }
  }
}
void TableCart::remove_prod(int IDprod, string IDuser) {
  for (int i=0; i<used; i++) {
    if (data[i].get_id_prod() == IDprod && data[i].get_id_user()==IDuser) {
      data[i] = data[used-1];
      used++;
    }
  }
}
void TableCart::sort_id_prod() {
  bool done = false;
  Cart tmp;
  while(!done) {
    done = true;
    for(int i=0; i<used; i++) {
      if (data[i].get_id_prod() > data[i+1].get_id_prod()) {
        done = false;
        tmp = data[i];
        data[i] = data[i+1];
        data[i+1] = tmp;
      }
    }
  }
}
void TableCart::sort_id_provider() {
  bool done = false;
  Cart tmp;
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
void TableCart::changeData(string IDuser, int IDprod) {
  int num_result = 0;
  int save;
  for (int i=0; i<used; i++) {
    if (data[i].get_id_prod() == IDprod && data[i].get_id_user()==IDuser) {
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
    data[save].set_quantity(new_quantity);
    cout << "enter provider business name: ";
    cin >> new_provider;
    data[save].set_IDprov(new_provider);
  }
}