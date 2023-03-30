//
// Created by Andrea Lipperi on 30/03/23.
//

#ifndef INGROSSO_ONLINE_USERNAMEGLOBAL_H
#define INGROSSO_ONLINE_USERNAMEGLOBAL_H

#include <string>

class UsernameGlobal {
public:
    static UsernameGlobal& GetInstance();
    std::string GetValue();
    void SetValue(std::string value);
private:
    UsernameGlobal();
    UsernameGlobal(const UsernameGlobal&) = delete;
    UsernameGlobal& operator=(const UsernameGlobal&) = delete;
    std::string value_;
};


#endif //INGROSSO_ONLINE_USERNAMEGLOBAL_H
