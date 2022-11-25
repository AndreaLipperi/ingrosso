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
  void add(const Orders& ord);
  void changeStatus(string IDcust, string IDprov);
private:
  void make_bigger();
  int capacity;
  Orders *data;
  int used;
};
#endif // INGROSSO_DB_DB_ORDERSMETHODS_H
