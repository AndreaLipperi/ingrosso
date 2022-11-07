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
  static int select_all_Categories();
  static int callback(void *NotUsed, int argc, char **argv, char **azColName);
  static int update_Categories(int CatID, string name);
  static int delete_Categories(int CatID);
  static int select_one_Categories(int CatID);
};


#endif //INGR_ONLINE_CATEGORIE_H
