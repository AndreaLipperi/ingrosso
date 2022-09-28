//
// Created by Matilde Tarchi on 29/07/22.
//

#ifndef INGR_ONLINE_CLIENTI_H
#define INGR_ONLINE_CLIENTI_H
#include "users.h"


class Customers:public Users{
public:
    explicit Customers (char t, char b_name, char city, char address,
                     char email, char psw, char u_name);



};


#endif //INGR_ONLINE_CLIENTI_H
