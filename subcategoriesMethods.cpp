///
// Created by Andrea Lipperi on 14/11/22.
//

#include "subcategoriesMethods.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

TableProducts::TableProducts() {
    used = 0;
    capacity = 5;
    data = new Products[capacity];
}
TableProducts::TableProducts(const TableProducts &other) {
    used = other.used;
    capacity = other.capacity;
    data = new Products[capacity];
    copy(other.data, other.data+used, data);
}
TableProducts::~TableProducts() {
    delete []data;
}

void TableProducts::operator=(const TableProducts &other) {
    if (&other == this) {
        return;
    }
    delete []data;
    capacity = other.capacity;
    used = other.used;
    data = new Products[capacity];
    copy(other.data, other.data+used, data);
}
void TableProducts::make_bigger() {
    Products *tmp;
    tmp = new Products[capacity + 5];
    copy(data, data+used,tmp);
    delete []data;
    data = tmp;
    capacity +=5;
}
void TableProducts::add(const Products& prod) {
    if (used>=capacity) {
        make_bigger();
    }
    data[used]= prod;
    used++;
}
void TableProducts::remove(const string &name) {
    for (int i=0; i<used; i++) {
        if (data[i].get_name() == name) {
            data[i] = data[used-1];
            used++;
        }
    }
}
void TableProducts::sort_id() {
    bool done = false;
    Products tmp;
    while(!done) {
        done = true;
        for(int i=0; i<used; i++) {
            if (data[i].get_name() > data[i+1].get_name()) {
                done = false;
                tmp = data[i];
                data[i] = data[i+1];
                data[i+1] = tmp;
            }
        }
    }
}
void TableProducts::changeData(const string &name) {
    int num_result = 0;
    int save;
    for (int i=0; i<used; i++) {
        if (data[i].get_name() == name) {
            num_result++;
            save=i;
            i=used;
        }
    }
    if (num_result>0) {
        string new_name;
        string new_descriprion;
        Categories *new_cat;
        data[save].set_name(new_name);
        data[save].set_cat(new_cat);
    }
}
string TableProducts::select_name(const string &name) {
    int num_result = 0;
    int save;
    for (int i=0; i<used; i++) {
        if (data[i].get_name() == name) {
            num_result++;
            save=i;
            i=used;
        }
    }
    return data[save].get_name();
}