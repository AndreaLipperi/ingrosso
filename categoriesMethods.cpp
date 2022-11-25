//
// Created by Andrea Lipperi on 14/11/22.
//

#include "categoriesMethods.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

TableCategories::TableCategories() {
  used = 0;
  capacity = 5;
  data = new Categories[capacity];
}
TableCategories::TableCategories(const TableCategories &other) {
  used = other.used;
  capacity = other.capacity;
  data = new Categories[capacity];
  copy(other.data, other.data+used, data);
}
TableCategories::~TableCategories() {
  delete []data;
}

void TableCategories::operator=(const TableCategories &other) {
  if (&other == this) {
    return;
  }
  delete []data;
  capacity = other.capacity;
  used = other.used;
  data = new Categories[capacity];
  copy(other.data, other.data+used, data);
}
void TableCategories::make_bigger() {
  Categories *tmp;
  tmp = new Categories[capacity + 5];
  copy(data, data+used,tmp);
  delete []data;
  data = tmp;
  capacity +=5;
}
void TableCategories::add(const Categories& cat) {
  if (used>=capacity) {
    make_bigger();
  }
  data[used]= cat;
  used++;
}
void TableCategories::remove(int id) {
  for (int i=0; i<used; i++) {
    if (data[i].get_id() == id) {
      data[i] = data[used-1];
      used++;
    }
  }
}
void TableCategories::sort_id() {
  bool done = false;
  Categories tmp;
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
void TableCategories::sort_name() {
  bool done = false;
  Categories tmp;
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
void TableCategories::changeName(int id) {
  int num_result = 0;
  int save;
  for (int i=0; i<used; i++) {
    if (data[i].get_id() == id) {
      cout << "Category found!" << endl;
      cout << data[i].get_name();
      num_result++;
      save=i;
      i=used;
    }
  }
  if (num_result>0) {
    string new_name;
    cout << "Enter new name: ";
    cin >> new_name;
    data[save].set_name(new_name);
  }
}
string TableCategories::select_name(int id) {
  int num_result = 0;
  int save;
  for (int i=0; i<used; i++) {
    if (data[i].get_id() == id) {
      num_result++;
      save=i;
      i=used;
    }
  }
  return data[save].get_name();
}