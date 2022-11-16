//
// Created by Matilde Tarchi on 02/08/22.
//

#include "cart.h"
#include <iostream>
#include <string>
using namespace std;

Cart::Cart() {
  ID=0;
  quantity=0;
  IDprod=0;
}

Cart::Cart(int new_id, int new_quantity, int new_id_prod, string new_id_user, string new_id_prov) {
  ID = new_id;
  quantity= new_quantity;
  IDprod=new_id_prod;
  IDuser=new_id_user;
  IDprovider=new_id_prov;
}

void Cart::output(ostream& outs) {
  if (&outs == &cout) {
    outs << "Quantity: " << quantity << endl;
    outs << "Product: " << TableProducts::select_name(IDprod) << endl;
    outs << "Provider: " << TableUsers::select_username(IDprovider) << endl;
  } else {
    outs <<  ID << endl;
    outs <<  TableProducts::select_name(IDprod) << endl;
    outs <<   TableUsers::select_username(IDprovider) << endl;
  }
}
void Cart::input(istream& ins) {
  if (&ins == &cin) {
    if (ins.peek() == '\n')ins.ignore();
    cout << "ID: ";
    ins >> ID;
    if (ins.peek() == '\n')ins.ignore();
    cout << "Quantity: ";
    ins>>quantity;
    if (ins.peek() == '\n')ins.ignore();
    cout << "ID product: ";
    ins>>IDprod;
    if (ins.peek() == '\n')ins.ignore();
    cout << "Business Name: ";
    ins >> IDuser;
    if (ins.peek() == '\n')ins.ignore();
    cout << "Business Name provider: ";
    ins >> IDprovider;
  }
}
