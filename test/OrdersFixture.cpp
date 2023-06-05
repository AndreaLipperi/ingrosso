//
// Created by Matilde Tarchi on 04/06/23.
//
//
// Created by Matilde Tarchi on 29/05/23.
//

#include "gtest/gtest.h"
#include "../storeMethods.h"
#include "../ordersMethods.h"
#include "../database.h"
#include "../store.h"
#include "../users.h"
#include "../orders.h"
#include <SQLiteCpp/Statement.h>




class OrdersSuite : public ::testing::Test {

protected:
    virtual void SetUp() {


    }

    string username = "andrea";
    string email = "andrealippe@gmail.com";
    TableOrders o1;
};

TEST_F(OrdersSuite, TestFindOrder) {

    string query_id="SELECT id FROM users WHERE username = '" + username + "'";
    int id = db.execAndGet(query_id).getInt();

    Orders order(10, 2, "S", "15/05/18", to_string(id), "114", ' ');
    o1.add(order);


    EXPECT_EQ(1, o1.select_count_for_client(username, 0));
}

TEST_F(OrdersSuite, TestChangeStatus) {


    string query_id_cust="SELECT id FROM users WHERE username = '" + username + "'";
    int idc = db.execAndGet(query_id_cust).getInt();
    string query_id_order="SELECT id FROM orders WHERE id_cust = '" + to_string(idc) + "'";
    int id = db.execAndGet(query_id_order).getInt();

    o1.changeStatus(username, to_string(id), "A");

    EXPECT_EQ(0, o1.select_count(username, 1));
}
TEST_F(OrdersSuite, TestDeleteOrder) {

    string query_id_user="SELECT id FROM users WHERE username = 'dario'";
    int id = db.execAndGet(query_id_user).getInt();

    string query_id_prov="SELECT id FROM orders WHERE id_prov = '" + to_string(id) + "'";
    int id2 = db.execAndGet(query_id_prov).getInt();

    TableOrders o1;
    o1.cancel_order(username, "5",to_string(id2));

    EXPECT_EQ(0, o1.select_count(username, 0));
}