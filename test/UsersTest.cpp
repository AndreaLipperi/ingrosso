//
// Created by Matilde Tarchi on 16/11/22.
//
#include "gtest/gtest.h"

#include "../usersMethods.h"


TEST(Users, TestFindUser) {
    TableUsers user;
    string e = "matilde.tarchi@gmail.com";
    string p = "ciao";
    EXPECT_EQ(0,user.access_reg(e,p,0));
}







