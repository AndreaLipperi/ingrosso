//
// Created by Andrea Lipperi on 14/11/22.
//

#include "productsMethods.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

TableProducts::TableProducts() {
  used = 0;
  capacity = 5;
  data = new Products[capacity];
}
TableProducts::TableProducts(const TableProducts &other) {
  used = other.used;
  capacity = other.capacity;
  data = new Products[capacity];
  copy(other.data, other.data+used, data);
}
TableProducts::~TableProducts() {
  delete []data;
}

void TableProducts::operator=(const TableProducts &other) {
  if (&other == this) {
    return;
  }
  delete []data;
  capacity = other.capacity;
  used = other.used;
  data = new Products[capacity];
  copy(other.data, other.data+used, data);
}
void TableProducts::make_bigger() {
  Products *tmp;
  tmp = new Products[capacity + 5];
  copy(data, data+used,tmp);
  delete []data;
  data = tmp;
  capacity +=5;
}
void TableProducts::display(int id_cat) {
  for (int i=0; i<used; i++) {
    if (data[i].get_id_cat()==id_cat) {
      data[i].output(cout);
    }
  }
}
void TableProducts::add(const Products& prod) {
  if (used>=capacity) {
    make_bigger();
  }
  data[used]= prod;
  used++;
}
void TableProducts::remove(int id) {
  for (int i=0; i<used; i++) {
    if (data[i].get_id() == id) {
      data[i] = data[used-1];
      used++;
    }
  }
}
void TableProducts::save(ostream &outs) {
  sort_id();
  for (int i=0; i<used; i++) {
    outs << data[i];
  }
}
void TableProducts::load(istream &ins) {
  Products tmp;
  while (ins >> tmp) {
    if (used>=capacity) {
      make_bigger();
    }
    data[used] = tmp;
    used++;
  }
}
void TableProducts::sort_id() {
  bool done = false;
  Products tmp;
  while(!done) {
    done = true;
    for(int i=0; i<used; i++) {
      if (data[i].get_id() > data[i+1].get_id()) {
        done = false;
        tmp = data[i];
        data[i] = data[i+1];
        data[i+1] = tmp;
      }
    }
  }
}
void TableProducts::sort_name() {
  bool done = false;
  Products tmp;
  while(!done) {
    done = true;
    for(int i=0; i<used; i++) {
      if (data[i].get_name() > data[i+1].get_name()) {
        done = false;
        tmp = data[i];
        data[i] = data[i+1];
        data[i+1] = tmp;
      }
    }
  }
}
void TableProducts::sort_id_cat() {
  bool done = false;
  Products tmp;
  while(!done) {
    done = true;
    for(int i=0; i<used; i++) {
      if (data[i].get_id_cat() > data[i+1].get_id_cat()) {
        done = false;
        tmp = data[i];
        data[i] = data[i+1];
        data[i+1] = tmp;
      }
    }
  }
}
void TableProducts::changeData(int id) {
  int num_result = 0;
  int save;
  for (int i=0; i<used; i++) {
    if (data[i].get_id() == id) {
      cout << "Products found!" << endl;
      data[i].output(cout);
      cout << "Name category" << data[i].get_cat_name(data[i].get_id()) << endl;
      num_result++;
      save=i;
      i=used;
    }
  }
  if (num_result>0) {
    string new_name;
    string new_descriprion;
    int new_id_cat;
    cout << "Enter new name: " << endl;
    cin >> new_name;
    data[save].set_name(new_name);
    cout << "Enter new description: " << endl;
    cin >> new_descriprion;
    data[save].set_description(new_descriprion);
    cout << "Enter new id category: " << endl;
    cin >> new_id_cat;
    data[save].set_IDcat(new_id_cat);
  }
}
string TableProducts::select_name(int id_prod) {
  int num_result = 0;
  int save;
  for (int i=0; i<used; i++) {
    if (data[i].get_id() == id_prod) {
      num_result++;
      save=i;
      i=used;
    }
  }
  return data[save].get_name();
}