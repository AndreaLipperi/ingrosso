//
// Created by Matilde Tarchi on 29/07/22.
//

#ifndef INGR_ONLINE_UTENTI_H
#define INGR_ONLINE_UTENTI_H
#include <string>
using namespace std;
class Users {
public:
    Users();
    Users(const std::string &new_type, const std::string &new_bus_name, const std::string &new_city, const std::string &new_address, const std::string &new_email, const std::string &new_pass, const std::string &new_username);
    string get_type() {
        return type;
    }
    string get_bus_name() {
        return business_name;
    }
    string get_address() {
        return address;
    }
    string get_city() {
        return city;
    }
    string get_email() {
        return email;
    }
    string get_psw() {
        return psw;
    }
    string get_username() {
        return username;
    }

    void set_psw(const std::string &new_psw){
        Users::psw=new_psw;
    }
private:
    std::string type;
    string business_name;
    std::string address;
    std::string city;
    std::string email;
    std::string psw;
    std::string username;
};

#endif //INGR_ONLINE_UTENTI_H