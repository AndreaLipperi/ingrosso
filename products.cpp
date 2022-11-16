//
// Created by Andrea Lipperi on 14/11/22.
//

#include "products.h"
#include <iostream>
#include <string>
using namespace std;

Products::Products() {
  ID=0;
  IDcat=0;
}

Products::Products(int new_id, std::string new_name, std::string new_description, int new_id_cat) {
  ID = new_id;
  name= new_name;
  description=new_description;
  IDcat=new_id_cat;
}

void Products::output(ostream& outs) {
  if (&outs == &cout) {
    outs << "ID: " << ID << endl;
    outs << "Name: " << name << endl;
    outs << "Description: " << description << endl;
    outs << "ID category: " << IDcat << endl;
  } else {
    outs <<  ID << endl;
    outs <<  name << endl;
    outs <<  description << endl;
    outs <<  IDcat << endl;
  }
}
void Products::input(istream& ins) {
  if (&ins == &cin) {
    if (ins.peek() == '\n')ins.ignore();
    cout << "ID: ";
    ins >> ID;
    if (ins.peek() == '\n')ins.ignore();
    cout << "Name: ";
    getline(ins,name);
    if (ins.peek() == '\n')ins.ignore();
    cout << "Description: ";
    getline(ins,description);
    if (ins.peek() == '\n')ins.ignore();
    cout << "ID category: ";
    ins >> IDcat;
  }
}
