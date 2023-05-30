//
// Created by Matilde Tarchi on 29/05/23.
//

#include "gtest/gtest.h"
#include "../storeMethods.h"
#include "../database.h"
#include "../store.h"
#include "../users.h"
#include "../usersMethods.h"
#include <SQLiteCpp/Statement.h>




class ProductsSuite : public ::testing::Test {

protected:
    virtual void SetUp() {

        string query="INSERT INTO users (type, business_name, address, id_city, email, password, username) VALUES ( 'F', 'dariomo', 'lala', 'ciao', 'dariomori02@gmail.com', 'Dadada02', 'dario');";
        db.exec(query);

    }

    Users user;
    string username = "dario";





};

    TEST_F(ProductsSuite, TestAddProduct) {

        string query_id="SELECT id FROM users WHERE username = 'dario'";
        int id = db.execAndGet(query_id).getInt();
        Store product("10", "1", "1,02", "ciao", to_string(id));
        TableStore p1;
        p1.add(product);
        EXPECT_EQ(1, p1.select_count_for_prov("dario"));
    }

    TEST_F(ProductsSuite, TestFindProduct) {
    }




