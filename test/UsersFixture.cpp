//
// Created by Matilde Tarchi on 16/11/22.
//
#include "gtest/gtest.h"
#include "../usersMethods.h"
#include "../users.h"
#include "../database.h"


class UsersSuite : public ::testing::Test {

protected:
    virtual void SetUp() {
        user.set_psw("ciao");
        string query="DELETE FROM users WHERE username = '" + username + "'";
        db.exec(query);
    }

    Users user;
    string username = "matilde.tarchi@gmail.com";
};



TEST_F(UsersSuite, TestFindUser) {
    TableUsers user;
    string e = username;
    string p = "ciao";
    EXPECT_EQ(0,user.access_reg(e,p,0));
    EXPECT_EQ(0,user.access_reg(e,p,1));
}
TEST_F(UsersSuite, TestAddUser) {
    string e = username;
    string p = "ciao";
    TableUsers sut;
    Users user("c", "mati", "soso", "matilde.tarchi", "psw", username, 3);

    sut.add(user);
    EXPECT_EQ(0,sut.access_reg(e,p,1));
}

