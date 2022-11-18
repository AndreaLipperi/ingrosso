//
// Created by Andrea Lipperi on 16/11/22.
//

#ifndef INGROSSO_DB_DB_ORDERSMETHODS_H
#define INGROSSO_DB_DB_ORDERSMETHODS_H

#include <string>
#include "orders.h"
using namespace std;
class TableOrders {
public :
  TableOrders();
  ~TableOrders();
  TableOrders(const TableOrders& other);
  void operator =(const TableOrders& other);
  void display(string IDuser, int control);
  void add(const Orders& ord);
  void changeStatus(string IDcust, string IDprov);
  void save(ostream& outs);
  void load(istream& ins);
private:
  void make_bigger();
  int capacity;
  Orders *data;
  int used;
};
#endif // INGROSSO_DB_DB_ORDERSMETHODS_H
