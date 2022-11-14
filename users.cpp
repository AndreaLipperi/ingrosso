//
// Created by Andrea Lipperi on 14/11/22.
//

#include "users.h"
#include <string>
#include <iostream>
using namespace std;

Users::Users() {}

Users::Users(std::string new_type, string new_bus_name, std::string new_city, std::string new_address, std::string new_email, std::string new_pass, std::string new_username) {
  type = new_type;
  business_name= new_bus_name;
  address = new_address;
  city = new_city;
  email = new_email;
  psw = new_pass;
  username = new_username;
}

void Users::output(ostream& outs) {
  if (&outs == &cout) {
    outs << "Type: " << type << endl;
    outs << "Business Name: " << business_name << endl;
    outs << "Address: " << address << endl;
    outs << "City: " << city << endl;
    outs << "email: " << email << endl;
    outs << "username: " << username << endl;
  } else {
    outs <<  type << endl;
    outs <<  business_name << endl;
    outs <<  address << endl;
    outs <<  city << endl;
    outs <<  email << endl;
    outs <<  username << endl;
  }
}
void Users::input(istream& ins) {
  if (&ins == &cin) {
    if (ins.peek() == '\n')ins.ignore();
    cout << "Type: ";
    getline(ins,type);
    if (ins.peek() == '\n')ins.ignore();
    cout << "Enter business name: ";
    getline(ins,business_name);
    cout << "Enter Address: ";
    if (ins.peek() == '\n')ins.ignore();
    getline(ins,address);
    cout << "Enter email: ";
    if (ins.peek() == '\n')ins.ignore();
    getline(ins,email);
    cout << "Enter password: ";
    if (ins.peek() == '\n')ins.ignore();
    getline(ins,psw);
    cout << "Enter username: ";
    if (ins.peek() == '\n')ins.ignore();
    getline(ins,username);
  }
}
