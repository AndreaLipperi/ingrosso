#include "categories.h"
#include "subcategories.h"
#include "users.h"
#include <iostream>
#include <sqlite3.h>
#include <stdio.h>
#include "wx/wx.h"
#include "MyApp.h"
#include <string>
using namespace std;

IMPLEMENT_APP(MyApp)
/*
 * int main() {
    Users *user;
    user = new Users("t","ciaosium","roma","viadelsium", "siumsiumsium","sium","siumdelsium");
    TableUsers *table;
    table = new TableUsers();
    table->add(*user);

    return 0;
}
 */
