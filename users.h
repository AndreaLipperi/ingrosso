//
// Created by Matilde Tarchi on 29/07/22.
//

#ifndef INGR_ONLINE_UTENTI_H
#define INGR_ONLINE_UTENTI_H
#include <string>
using namespace std;

class Users {
public:
    explicit Users(string t, string b_name, string c, string a,
                 string email, string psw, string u_name);


private:
    string type,business_name, city, address,
            email, psw, user_name;

};



#endif //INGR_ONLINE_UTENTI_H
