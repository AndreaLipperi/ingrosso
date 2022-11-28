//
// Created by Andrea Lipperi on 16/11/22.
//


#include <fstream>
#include <iostream>
#include <string>
#include "storeMethods.h"
using namespace std;
TableStore::TableStore() {
  used = 0;
  capacity = 5;
  data = new Store[capacity];
}
TableStore::~TableStore() {
  delete []data;
}
TableStore::TableStore(const TableStore &other) {
  used = other.used;
  capacity = other.capacity;
  data = new Store[capacity];
  copy(other.data, other.data+used, data);
}
void TableStore::operator=(const TableStore &other) {
  if (&other == this) {
    return;
  }
  delete []data;
  capacity = other.capacity;
  used = other.used;
  data = new Store[capacity];
  copy(other.data, other.data+used, data);
}
void TableStore::make_bigger() {
  Store *tmp;
  tmp = new Store[capacity + 5];
  copy(data, data+used,tmp);
  delete []data;
  data = tmp;
  capacity +=5;
}
void TableStore::add(const Store& store) {
  if (used>=capacity) {
    make_bigger();
  }
  data[used]= store;
  used++;
}
void TableStore::remove(int id) {
  for (int i=0; i<used; i++) {
    if (data[i].get_id() == id) {
      data[i] = data[used-1];
      used++;
    }
  }
}
void TableStore::changeQuantity(Products *prod, const string &id_prov){
  int num_result = 0;
  int save;
  for (int i=0; i<used; i++) {
    if (data[i].get_prod() == prod && data[i].get_id_prov()==id_prov) {
      num_result++;
      save=i;
      i=used;
    }
  }
  if (num_result>0) {
    int new_quantity;
    cout << "Enter new quantity: ";
    cin >> new_quantity;
    data[save].set_quantity(new_quantity);
  }
}

void TableStore::changeDesc(Products *prod, const string &id_prov){
  int num_result = 0;
  int save;
  for (int i=0; i<used; i++) {
    if (data[i].get_prod() == prod && data[i].get_id_prov()==id_prov) {
      num_result++;
      save=i;
      i=used;
    }
  }
  if (num_result>0) {
    string new_desc;
    cout << "Enter new description: ";
    cin >> new_desc;
    data[save].set_desc(new_desc);
  }
}