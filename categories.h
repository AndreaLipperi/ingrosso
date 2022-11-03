//
// Created by Matilde Tarchi on 29/07/22.
//

#ifndef INGR_ONLINE_CATEGORIE_H
#define INGR_ONLINE_CATEGORIE_H
#include <string>
using namespace std;
class Categories {
public:
  static int add_Categories(string name);
  static int select_categories();
  static int callback(void *NotUsed, int argc, char **argv, char **azColName);
  static int update_Categories(int CatID, string name);
};


#endif //INGR_ONLINE_CATEGORIE_H
