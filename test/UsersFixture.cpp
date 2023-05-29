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
        string query="DELETE FROM users WHERE username = '" + email + "'";
        db.exec(query);
    }

    Users user;
    string email = "matilde.tarchi@gmail.com";
};



TEST_F(UsersSuite, TestFindUser) {
    TableUsers user;
    string e = email;
    string p = "ciao";
    EXPECT_EQ(0,user.access_reg(e,p,0));
    EXPECT_EQ(0,user.access_reg(e,p,1));
}
TEST_F(UsersSuite, TestAddUser) {
    //string e = username;
    string p = "Ciaociao02";
    TableUsers sut;
    Users user("C", "mati", "soso", email, "Ciaociao02", "matilde.tarchi", 3);

    sut.add(user);
    EXPECT_EQ(1,sut.access_reg(email,p,0));
}
TEST_F(UsersSuite, TestChangeDataUser) {
    string e = email;
    string p = "Ciaociao02";
    TableUsers sut;
    Users user1("C", "mati", "soso", email, "Ciaociao02", "matilde", 3);

    sut.changeData("matilde.tarchi",user1);
    EXPECT_EQ(1,sut.access_reg(e,p,0));
}

TEST_F(UsersSuite, TestRemoveUser) {
    string e = email;
    string p = "Ciaociao02";
    TableUsers sut;

    sut.remove("matilde","C");
    EXPECT_EQ(0,sut.access_reg(e,p,0));
}



