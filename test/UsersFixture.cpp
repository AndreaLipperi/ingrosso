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



TEST_F(UsersSuite, TestFindUser) {
    TableUsers user;
    string e = "matilde.tarchi@gmail.com";
    string p = "ciao";
    EXPECT_EQ(0,user.access_reg(e,p,0));
    EXPECT_EQ(0,user.access_reg(e,p,1));
}
TEST_F(UsersSuite, TestAddUser) {
    string e = "matilde.tarchi@gmail.com";
    string p = "ciao";
    TableUsers sut;
    Users user("c","mati","firenze","cisi",
               e,p,"cici");

    sut.add(user);
    EXPECT_EQ(0,sut.access_reg(e,p,1));
}
