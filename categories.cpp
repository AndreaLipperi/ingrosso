//
// Created by Andrea Lipperi on 14/11/22.
//

#include "categories.h"
#include <iostream>
#include <string>
using namespace std;

Categories::Categories() {
  ID=0;
}

Categories::Categories(int new_id,std::string new_name) {
  ID = new_id;
  name= new_name;
}

void Categories::output(ostream& outs) {
  if (&outs == &cout) {
    outs << "ID: " << ID << endl;
    outs << "Name: " << name << endl;
  } else {
    outs <<  ID << endl;
    outs <<  name << endl;
  }
}
void Categories::input(istream& ins) {
  if (&ins == &cin) {
    if (ins.peek() == '\n')ins.ignore();
    cout << "ID: ";
    ins >> ID;
    if (ins.peek() == '\n')ins.ignore();
    cout << "Name: ";
    getline(ins,name);
  }
}
