//
// Created by Matilde Tarchi on 29/07/22.
//

#ifndef INGR_ONLINE_UTENTI_H
#define INGR_ONLINE_UTENTI_H

#include <string>
using namespace std;
class Users {
public:
  Users();
  Users(std::string new_type, string new_bus_name, std::string new_city, string new_address, string new_email, string new_pass, string new_username);
  string get_type() {
    return type;
  }
  string get_bus_name() {
    return business_name;
  }
  string get_address() {
    return address;
  }
  string get_city() {
    return city;
  }
  string get_email() {
    return email;
  }
  string get_psw() {
    return psw;
  }
  string get_username() {
    return username;
  }
  void output(ostream& outs);
  void input(istream& ins);
  friend ostream& operator<<(ostream& outs, Users& tmp) {
    tmp.output(outs);
    return outs;
  }
  friend istream& operator>>(istream& ins, Users& tmp) {
    tmp.input(ins);
    return ins;
  }
  void set_psw(string new_psw){
    Users::psw=new_psw;
  }
private:
  std::string type;
  string business_name;
  std::string address;
  std::string city;
  std::string email;
  std::string psw;
  std::string username;
};


#endif //INGR_ONLINE_UTENTI_H
