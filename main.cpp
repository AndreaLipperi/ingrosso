#include <iostream>
#include <string>
#include <sqlite3.h>
#include "users.h"
using namespace std;

int main() {

  Users* user;
  string type,business_name, city, address,
      email, psw, user_name;
  cout <<"inserire dati utente\n";
  cout << "Tipo: \n";
  cin >> type;
  cout << "Business Name: \n";
  cin >> business_name;
  cout << "Città: \n";
  cin >> city;
  cout << "Indirizzo: \n";
  cin >> address;
  cout << "Email: \n";
  cin >> email;
  cout << "Password: \n";
  cin >> psw;
  cout << "User Name: \n";
  cin >> user_name;
  user = new Users(type,business_name,city,address,email,psw,user_name);
    return 0;
}
