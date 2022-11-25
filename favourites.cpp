//
// Created by Matilde Tarchi on 02/08/22.
//

#include "favourites.h"
#include <iostream>
#include <string>
using namespace std;

Favourites::Favourites() {
  ID=0;
  quantity=0;
  IDprod=0;
}

Favourites::Favourites(int new_id, int new_quantity, int new_id_prod, string new_id_cust, string new_id_prov) {
  ID = new_id;
  quantity= new_quantity;
  IDprod=new_id_prod;
  IDcustomer=new_id_cust;
  IDprovider=new_id_prov;
}

void Favourites::output(ostream& outs) {
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
void Favourites::input(istream& ins) {
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
    ins >> IDcustomer;
    if (ins.peek() == '\n')ins.ignore();
    cout << "Business Name provider: ";
    ins >> IDprovider;
  }
}
