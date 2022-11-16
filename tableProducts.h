//
// Created by Andrea Lipperi on 16/11/22.
//

#ifndef INGROSSO_DB_DB_TABLEPRODUCTS_H
#define INGROSSO_DB_DB_TABLEPRODUCTS_H

#include <string>
#include "products.h"
class TableProducts {
public :
  TableProducts();
  ~TableProducts();
  TableProducts(const TableProducts& other);
  void operator =(const TableProducts& other);
  void display(int id_cat);
  void add(const Products& prod);
  string select_name(int id_prod);
  void remove(int id);
  void changeData(int id);
  void save(ostream& outs);
  void load(istream& ins);
  void sort_id();
  void sort_name();
  void sort_id_cat();
private:
  void make_bigger();
  int capacity;
  Products *data;
  int used;
};

#endif // INGROSSO_DB_DB_TABLEPRODUCTS_H
