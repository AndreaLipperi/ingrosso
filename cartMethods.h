//
// Created by Andrea Lipperi on 16/11/22.
//

#ifndef INGROSSO_DB_DB_CARTMETHODS_H
#define INGROSSO_DB_DB_CARTMETHODS_H

#include <string>
#include "cart.h"
using namespace std;
class TableCart {
public :
  TableCart();
  ~TableCart();
  TableCart(const TableCart& other);
  void operator =(const TableCart& other);
  void add(const Cart& cart);
  void remove_all(string IDuser);
  void remove_prod(int IDprod, string IDuser);
  void changeData(string IDuser, int IDprod);
  void sort_id_prod();
  void sort_id_provider();
private:
  void make_bigger();
  int capacity;
  Cart *data;
  int used;
};

#endif // INGROSSO_DB_DB_CARTMETHODS_H
