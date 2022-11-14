//
// Created by Andrea Lipperi on 14/11/22.
//

#ifndef INGROSSO_DB_DB_DATABASE_H
#define INGROSSO_DB_DB_DATABASE_H

#include <string>
#include "users.h"
using namespace std;
class Database{
public :
  Database();
  ~Database();
  Database(const Database& other);
  void operator =(const Database& other);
  void search(string email);
  void search_bus_name(string business_name);
  void add(const Users& emp);
  void display_all();
  void remove(string business_name);
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



#endif // INGROSSO_DB_DB_DATABASE_H
