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
    string username = "dario";
    string email = "dariomori@gmail.com";
    virtual void SetUp() {


        //string query="INSERT INTO users (type, business_name, address, id_city, email, password, username) VALUES ( 'F', 'dariomo', 'lala', 'ciao', 'dariomori02@gmail.com', 'Dadada02', 'dario');";
       // db.exec(query);
       // string query="DELETE FROM users WHERE email = '" + email + "'";
      //  db.exec(query);

        TableUsers sut;
        string p = "Dadada02";

        if(sut.access_reg(email,p,0) == 0){
            Users user("F", "dada", "soso", email, p, username, 3);

            sut.add(user);

        }
    }
};

    TEST_F(ProductsSuite, TestAddProduct) {

        string query_id="SELECT id FROM users WHERE username = '" + username + "'";
        int id = db.execAndGet(query_id).getInt();
        Store product("10", "2", "1,02", "ciao", to_string(id));

        TableStore p1;
        p1.add(product);
        EXPECT_EQ(1, p1.select_count_for_prov(username));
    }

    TEST_F(ProductsSuite, TestFindProducts) {


        string query_id="SELECT id FROM users WHERE username = '" + username + "'";
         int id = db.execAndGet(query_id).getInt();

        string query_delprod="DELETE FROM store WHERE id_prov ='" + to_string(id) + "'";
        db.exec(query_delprod);

            string query_insert="INSERT INTO store (available_quantity, price_product, desc_prod,id_sub, id_prov, id_intern) VALUES ('8', '12', '2', '2', '" + to_string(id) + "', '');";

            db.exec(query_insert);
        TableStore p1;
        EXPECT_EQ(1, p1.select_count_for_prov(username));
    }

   TEST_F(ProductsSuite, TestDeleteProducts) {

        string query_id_user="SELECT id FROM users WHERE username = '" + username + "'";
        int id = db.execAndGet(query_id_user).getInt();

        string query_id_prod="SELECT id FROM store WHERE id_prov = '" + to_string(id) + "'";
        int id2 = db.execAndGet(query_id_prod).getInt();

        TableStore p1;
        EXPECT_EQ(1, p1.remove(id2));
    }


