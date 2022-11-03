//
// Created by Matilde Tarchi on 29/07/22.
//

#ifndef INGR_ONLINE_UTENTI_H
#define INGR_ONLINE_UTENTI_H
#include <string>
using namespace std;

class Users {
public:
  static int add_Users(string type, string business_name, string city, string address,
                 string email, string psw, string user_name);


};



#endif //INGR_ONLINE_UTENTI_H
