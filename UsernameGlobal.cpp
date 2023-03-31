//
// Created by Andrea Lipperi on 30/03/23.
//

#include "UsernameGlobal.h"

UsernameGlobal::UsernameGlobal() : value_username(""), value_type("") {}

UsernameGlobal& UsernameGlobal::GetInstance() {
    static UsernameGlobal instance;
    return instance;
}

std::string UsernameGlobal::GetValueUsername() {
    return value_username;
}
std::string UsernameGlobal::GetValueType() {
    return value_type;
}

void UsernameGlobal::SetValueUsername(std::string value_u) {
    value_username = value_u;
}
void UsernameGlobal::SetValueType(std::string value_t) {
    value_type = value_t;
}