//
// Created by Andrea Lipperi on 14/11/22.
//

#ifndef INGROSSO_DB_DB_TABLEUSERSDB_H
#define INGROSSO_DB_DB_TABLEUSERSDB_H

#include <string>
#include "users.h"
using namespace std;
class TableUsers{
public :
  TableUsers();
  ~TableUsers();
  TableUsers(const TableUsers& other);
  void operator =(const TableUsers& other);
  int access(string email, string psw, int control);
  //void search_bus_name(string business_name);
  void add(const Users& emp);
  //void display_all();
  void remove(string business_name);
  void changePsw(string psw);
  void save(ostream& outs);
  void load(istream& ins);
  void sort_email();
  void sort_bus_name();
private:
  void make_bigger();
  int capacity;
  Users *data;
  int used;
};



#endif // INGROSSO_DB_DB_TABLEUSERSDB_H
