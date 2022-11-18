//
// Created by Andrea Lipperi on 14/11/22.
//

#include "store.h"
#include <iostream>
#include <string>
using namespace std;

Store::Store() {
  ID=0;
  available_quantity=0;
  IDproduct=0;
  price_product=0;
}

Store::Store(int new_id,int new_quantity, int new_id_prod, int new_price, string new_desc, string new_id_prov) {
  ID = new_id;
  available_quantity=new_quantity;
  IDproduct=new_id_prod;
  price_product=new_price;
  description_prod=new_desc;
  IDprovider=new_id_prov;
}

void Store::output(ostream& outs) {
  /*if (&outs == &cout) {
    outs << "ID: " << ID << endl;
    outs << "quantity: " << name << endl;
  } else {
    outs <<  ID << endl;
    outs <<  name << endl;
  }*/
}
void Store::input(istream& ins) {
  /*if (&ins == &cin) {
    if (ins.peek() == '\n')ins.ignore();
    cout << "ID: ";
    ins >> ID;
    if (ins.peek() == '\n')ins.ignore();
    cout << "Name: ";
    getline(ins,name);
  }*/
}
