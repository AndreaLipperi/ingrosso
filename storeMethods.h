//
// Created by Andrea Lipperi on 16/11/22.
//

#ifndef INGROSSO_DB_DB_STOREMETHODS_H
#define INGROSSO_DB_DB_STOREMETHODS_H


#include <string>
#include "store.h"
using namespace std;
class TableStore {
public :
  TableStore();
  ~TableStore();
  TableStore(const TableStore& other);
  void operator =(const TableStore& other);
  void add(const Store& store);
  void remove(int id);
  void changeQuantity(int id_prod, string id_prov);
  void changeDesc(int id_prod, string id_prov);
  void save(ostream& outs);
  void load(istream& ins);
  /*void sort_id();
  void sort_name();*/
private:
  void make_bigger();
  int capacity;
  Store *data;
  int used;
};

#endif // INGROSSO_DB_DB_STOREMETHODS_H
