//
// Created by Andrea Lipperi on 14/11/22.
//

#include "users.h"
#include "usersMethods.h"
#include <iostream>
#include <string>
using namespace std;

Users::Users(const std::string &new_type, const std::string &new_bus_name, const std::string &new_address, const std::string &new_email, const std::string &new_pass, const std::string &new_username, int new_city){
    type = new_type;
    business_name= new_bus_name;
    address = new_address;
    id_city = new_city;
    email = new_email;
    psw = new_pass;
    username = new_username;
}

Users::Users() {

}
