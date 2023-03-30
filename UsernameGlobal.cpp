//
// Created by Andrea Lipperi on 30/03/23.
//

#include "UsernameGlobal.h"

UsernameGlobal::UsernameGlobal() : value_("") {}

UsernameGlobal& UsernameGlobal::GetInstance() {
    static UsernameGlobal instance;
    return instance;
}

std::string UsernameGlobal::GetValue() {
    return value_;
}

void UsernameGlobal::SetValue(std::string value) {
    value_ = value;
}