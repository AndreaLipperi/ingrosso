//
// Created by Matilde Tarchi on 29/07/22.
//

#ifndef INGR_ONLINE_FORNITORI_H
#define INGR_ONLINE_FORNITORI_H
#include "users.h"

class Providers: public Users {
public:
    explicit Providers(char cat, char iban, char t, char b_name,
                       char c, char a, char email,
                       char psw, char u_name);


private:
    char categories, iban;

};



#endif //INGR_ONLINE_FORNITORI_H
