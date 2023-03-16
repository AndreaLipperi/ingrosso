//
// Created by Andrea Lipperi on 14/11/22.
//

#ifndef INGROSSO_ONLINE_USERSMETHODS_H
#define INGROSSO_ONLINE_USERSMETHODS_H

#include <string>
#include "users.h"
using namespace std;
class TableUsers{
public :
    TableUsers();
    int access_reg(const string &email, const string &psw, int control);
    void add(const Users& emp);
    void remove(const string &business_name);
    int changePsw(const string &psw,const string &new_psw);
    string select_username(const string &business_name);
    string select_type(const string &email);
private:
    Users data;
};



#endif // INGROSSO_ONLINE_USERSMETHODS_H