//
// Created by Andrea Lipperi on 14/11/22.
//

#ifndef INGROSSO_DB_DB_USERSMETHODS_H
#define INGROSSO_DB_DB_USERSMETHODS_H

#include <string>
#include "users.h"
using namespace std;
class TableUsers{
public :
  TableUsers();
  ~TableUsers();
  TableUsers(const TableUsers& other);
  void operator =(const TableUsers& other);
  int access_reg(string email, string psw, int control);
  void add(const Users& emp);
  void remove(string business_name);
  void changePsw(string psw);
  string select_username(string business_name);
  string  select_type(const std::string &email);
  void sort_email();
  void sort_bus_name();
private:
  void make_bigger();
  int capacity;
  Users *data;
  int used;
};



#endif // INGROSSO_DB_DB_USERSMETHODS_H
