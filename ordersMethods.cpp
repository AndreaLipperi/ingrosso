//
// Created by Andrea Lipperi on 14/11/22.
//

#define from_customer 0
#define from_provider 1
#include "ordersMethods.h"
#include <SQLiteCpp/SQLiteCpp.h>
#include <SQLiteCpp/Statement.h>
#include <SQLiteCpp/Database.h>
#include <iostream>
#include <string>
using namespace std;


TableOrders::TableOrders() {
    used = 0;
    capacity = 5;
    data = new Orders[capacity];
}
TableOrders::~TableOrders() {
    delete []data;
}

void TableOrders::add(const Orders& ord) {
    if (used>=capacity) {
        make_bigger();
    }
    data[used]= ord;
    used++;
}
void TableOrders::changeStatus(const string &IDcust, const string &IDprov){
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