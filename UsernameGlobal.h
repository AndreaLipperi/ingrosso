//
// Created by Andrea Lipperi on 30/03/23.
//

#ifndef INGROSSO_ONLINE_USERNAMEGLOBAL_H
#define INGROSSO_ONLINE_USERNAMEGLOBAL_H

#include <string>

class UsernameGlobal {
public:
    static UsernameGlobal& GetInstance();
    std::string GetValueType();
    std::string GetValueUsername();
    void SetValueUsername(std::string value_u);
    void SetValueType(std::string value_t);
private:
    UsernameGlobal();
    UsernameGlobal(const UsernameGlobal&) = delete;
    UsernameGlobal& operator=(const UsernameGlobal&) = delete;
    std::string value_username;
    std::string value_type;
};


#endif //INGROSSO_ONLINE_USERNAMEGLOBAL_H
