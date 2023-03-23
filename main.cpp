#include "categories.h"
#include "categoriesMethods.h"
#include "subcategoriesMethods.h"
#include "cartMethods.h"
#include "subcategories.h"
#include "usersMethods.h"
#include "users.h"
#include <SQLiteCpp/SQLiteCpp.h>
#include <SQLiteCpp/Statement.h>
#include <SQLiteCpp/Database.h>
#include <iostream>
#include <vector>
#include <sqlite3.h>
#include <stdio.h>
#include "wx/wx.h"
#include "MyApp.h"
#include <string>
using namespace std;

IMPLEMENT_APP(MyApp)
/*
  int main() {
    TableCategories table_cat;

    TableProducts table_sub;
    int id;
    //int n= table.number_of_cat();
    std::vector<std::string> categories;
    std::vector<std::string> subcategories;
    //cout << n;
    categories=table_cat.select();
    for (int i=0; i<categories.size(); i++){
        cout << i << " " << categories[i] << endl;
    }
    cout << "digita il numero della categoria della quale vuoi vedere le sottocategorie"<< endl;
    cin >> id;

    subcategories=table_sub.select(categories[id]);
    for (int i=0; i<subcategories.size(); i++){
        cout << i << " " << subcategories[i] << endl;
    }

}*/

