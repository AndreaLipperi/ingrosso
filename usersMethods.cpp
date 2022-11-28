//
// Created by Andrea Lipperi on 14/11/22.
//

#include "usersMethods.h"
#include <fstream>
#include <iostream>
#include <string>
#define accesso 0
#define registrazione 1
using namespace std;

TableUsers::TableUsers() {
  used = 0;
  capacity = 5;
  data = new Users[capacity];
}
TableUsers::TableUsers(const TableUsers &other) {
  used = other.used;
  capacity = other.capacity;
  data = new Users[capacity];
  copy(other.data, other.data+used, data);
}
TableUsers::~TableUsers() {
  delete []data;
}

void TableUsers::operator=(const TableUsers &other) {
  if (&other == this) {
    return;
  }
  delete []data;
  capacity = other.capacity;
  used = other.used;
  data = new Users[capacity];
  copy(other.data, other.data+used, data);
}
void TableUsers::make_bigger() {
  Users *tmp;
  tmp = new Users[capacity + 5];
  copy(data, data+used,tmp);
  delete []data;
  data = tmp;
  capacity +=5;
}
int TableUsers::access_reg(string email, string psw, int control) {
  //control =0 accesso normale
  //control = 1 per controllo se utente già esistente in caso di registrazione
  int num_found =0;
  if (control==accesso) {
    for (int i = 0; i < used; i++) {
      if (data[i].get_email() == email && data[i].get_psw() == psw) {
        num_found++;
      }
    }
    if (num_found == 0) {
      return 0;
    } else {
      return 1;
    }
  } else if(control==registrazione){
    for (int i = 0; i < used; i++) {
      if (data[i].get_email() == email) {
        num_found++;
      }
    }
    if (num_found == 0) {
      return 0;
    } else {
      return 1;
    }
  }
}
void TableUsers::add(const Users& emp) {
  if (used>=capacity) {
    make_bigger();
  }
  data[used]= emp;
  used++;
}
void TableUsers::remove(string business_name) {
  for (int i=0; i<used; i++) {
    if (data[i].get_bus_name() == business_name) {
      data[i] = data[used-1];
      used++;
    }
  }
}
void TableUsers::sort_email() {
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
void TableUsers::sort_bus_name() {
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
void TableUsers::changePsw(string email) {
  int num_result = 0;
  int save;
  for (int i=0; i<used; i++) {
    if (data[i].get_email() == email) {
      cout << "Employee found!" << endl;
      num_result++;
      save=i;
      i=used;
    }
  }
  if (num_result>0) {
    string new_psw;
    cout << "Enter new password: ";
    cin >> new_psw;
    data[save].set_psw(new_psw);
  }
}
string TableUsers::select_username(std::string business_name) {
  int save;
  for (int i=0; i<used; i++) {
    if (data[i].get_bus_name() == business_name) {
      cout << data[i].get_username()<< endl;
      save=i;
      i=used;
    }
  }
  return data[save].get_username();
}
string TableUsers::select_type(const std::string &email) {
  int save;
  for (int i=0; i<used; i++) {
    if (data[i].get_email() == email) {
      save=i;
      i=used;
    }
  }
  return data[save].get_type();
}