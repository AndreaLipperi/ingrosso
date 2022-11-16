//
// Created by Andrea Lipperi on 16/11/22.
//

#ifndef INGROSSO_DB_DB_TABELCATEGORIES_H
#define INGROSSO_DB_DB_TABELCATEGORIES_H

#include <string>
#include "categories.h"
using namespace std;
class TableCategories {
public :
  TableCategories();
  ~TableCategories();
  TableCategories(const TableCategories& other);
  void operator =(const TableCategories& other);
  void display();
  void add(const Categories& cat);
  void remove(int id);
  string select_name(int id);
  void changeName(int id);
  void save(ostream& outs);
  void load(istream& ins);
  void sort_id();
  void sort_name();
private:
  void make_bigger();
  int capacity;
  Categories *data;
  int used;
};

#endif // INGROSSO_DB_DB_TABELCATEGORIES_H
