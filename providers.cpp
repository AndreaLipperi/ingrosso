//
// Created by Matilde Tarchi on 02/08/22.
//

#include "providers.h"
#include "users.h"


Providers::Providers (char cat, char iban, char t, char b_name, char c, char a,
                  char email, char psw, char u_name) :
                 Users(t,b_name,c,a,
                        email,psw,u_name), categories(cat),iban(iban)  {
}