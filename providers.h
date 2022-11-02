//
// Created by Matilde Tarchi on 29/07/22.
//

#ifndef INGR_ONLINE_FORNITORI_H
#define INGR_ONLINE_FORNITORI_H
#include "users.h"
#include <string>
using namespace std;
class Providers: public Users {
public:
    /*explicit Providers(char cat, char iban, string t, string b_name,
                     string c, string a, string email,
                     string psw, string u_name);*/


private:
  char categories, iban;

};



#endif //INGR_ONLINE_FORNITORI_H
