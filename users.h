//
// Created by Matilde Tarchi on 29/07/22.
//

#ifndef INGR_ONLINE_UTENTI_H
#define INGR_ONLINE_UTENTI_H


class Users {
public:
    explicit Users(char t, char b_name, char c, char a,
                   char email, char psw, char u_name);


private:
    char type,business_name, city, address,
            email, psw, user_name;

};



#endif //INGR_ONLINE_UTENTI_H
