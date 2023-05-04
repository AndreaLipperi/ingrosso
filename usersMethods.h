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
    int remove(const string &username, const string &type);
    int changeData(const string &email, Users &user);
    string** select_data(const string &username);
    string select_type(const string &email);
    string select_username(const string &email);
    string select_email(const string &username);
private:
    Users data;
};



#endif // INGROSSO_ONLINE_USERSMETHODS_H