#include <iostream>
#include <string>
#include <sqlite3.h>
#include "users.h"
#include "categories.h"
using namespace std;

int main() {

 string type,business_name, city, address,
      email, psw, user_name, nameCat;
 int CatID;
 /* cout <<"inserire dati utente\n";
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
  Users::add_Users(type,business_name,city,address,email,psw,user_name);
  */
 cout << "Id categoria da modificare: \n";
 cin >> CatID;
  cout << "nuovo Nome categoria: \n";
  cin >> nameCat;
  Categories::update_Categories(CatID,nameCat);
  Categories::select_categories();
  return 0;
}
