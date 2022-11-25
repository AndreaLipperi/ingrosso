//
// Created by Andrea Lipperi on 14/11/22.
//

#include "ordersMethods.h"
#include <fstream>
#include <iostream>
#include <string>
#define from_customer 0
#define from_provider 1
using namespace std;

TableOrders::TableOrders() {
  used = 0;
  capacity = 5;
  data = new Orders[capacity];
}
TableOrders::TableOrders(const TableOrders &other) {
  used = other.used;
  capacity = other.capacity;
  data = new Orders[capacity];
  copy(other.data, other.data+used, data);
}
TableOrders::~TableOrders() {
  delete []data;
}

void TableOrders::operator=(const TableOrders &other) {
  if (&other == this) {
    return;
  }
  delete []data;
  capacity = other.capacity;
  used = other.used;
  data = new Orders[capacity];
  copy(other.data, other.data+used, data);
}
void TableOrders::make_bigger() {
  Orders *tmp;
  tmp = new Orders[capacity + 5];
  copy(data, data+used,tmp);
  delete []data;
  data = tmp;
  capacity +=5;
}
void TableOrders::add(const Orders& ord) {
  if (used>=capacity) {
    make_bigger();
  }
  data[used]= ord;
  used++;
}
void TableOrders::changeStatus(std::string IDcust, std::string IDprov){
  int num_result = 0;
  int save;
  for (int i=0; i<used; i++) {
    if (data[i].get_id_cust() == IDcust && data[i].get_id_prov()==IDprov) {
      num_result++;
      save=i;
      i=used;
    }
  }
  if (num_result>0) {
    string new_status;
    cout << "Enter new status: ";
    cin >> new_status;
    data[save].set_status(new_status);
  }
}