//
// Created by Andrea Lipperi on 14/11/22.
//

#include "database.h"
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

Database::Database() {
  used =0;
  capacity = 5;
  data = new Users[capacity];
}
Database::Database(const Database &other) {
  used = other.used;
  capacity = other.capacity;
  data = data = new Users[capacity];
  copy(other.data, other.data+used, data);
}
Database::~Database() {
  delete []data;
}

void Database::operator=(const Database &other) {
  if (&other == this) {
    return;
  }
  delete []data;
  capacity = other.capacity;
  used = other.used;
  data = new Users[capacity];
  copy(other.data, other.data+used, data);
}
void Database::make_bigger() {
  Users *tmp;
  tmp = new Users[capacity + 5];
  copy(data, data+used,tmp);
  delete []data;
  data = tmp;
  capacity +=5;
}
void Database::search(string email) {
  int num_found =0;
  for (int i=0; i<used; i++) {
    if (data[i].get_email() == email) {
      cout << "found!" << endl;
      data[i].output(cout);
      num_found++;
    }
  }
  if (num_found == 0) {
    cout << "No employee found" << endl;
  }
}
void Database::search_bus_name(string business_name) {
  int num_found =0;
  for (int i=0; i<used; i++) {
    if (data[i].get_bus_name() == business_name) {
      cout << "Employee found!" << endl;
      data[i].output(cout);
      num_found++;
    }
  }
  if (num_found == 0) {
    cout << "No employee found" << endl;
  }
}
void Database::add(const Users& emp) {
  if (used>=capacity) {
    make_bigger();
  }
  data[used]= emp;
  used++;
}
void Database::display_all() {
  for (int i=0; i<used; i++) {
    data[i].output(cout);
  }
}
void Database::remove(string business_name) {
  for (int i=0; i<used; i++) {
    if (data[i].get_bus_name() == business_name) {
      data[i] = data[used-1];
      used++;
    }
  }
}
void Database::save(ostream &outs) {
  sort_email();
  for (int i=0; i<used; i++) {
    outs << data[i];
  }
}
void Database::load(istream &ins) {
  Users tmp;
  while (ins >> tmp) {
    if (used>=capacity) {
      make_bigger();
    }
    data[used] = tmp;
    used++;
  }
}
void Database::sort_email() {
  bool done = false;
  Users tmp;
  while(!done) {
    done = true;
    for(int i=0; i<used; i++) {
      if (data[i].get_email() > data[i+1].get_email()) {
        done = false;
        tmp = data[i];
        data[i] = data[i+1];
        data[i+1] = tmp;
      }
    }
  }
}
void Database::sort_bus_name() {
  bool done = false;
  Users tmp;
  while(!done) {
    done = true;
    for(int i=0; i<used; i++) {
      if (data[i].get_bus_name() > data[i+1].get_bus_name()) {
        done = false;
        tmp = data[i];
        data[i] = data[i+1];
        data[i+1] = tmp;
      }
    }
  }
}