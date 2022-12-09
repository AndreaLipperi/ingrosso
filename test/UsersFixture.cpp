//
// Created by Matilde Tarchi on 16/11/22.
//
#include "gtest/gtest.h"
#include "../usersMethods.h"
#include "../users.h"


class UsersSuite : public ::testing::Test {

protected:
    virtual void SetUp() {
        user.set_psw("ciao");
    }

    Users user;
};


TEST_F(UsersSuite, Test) {
    //da completare
}
