//
// Created by Matilde Tarchi on 29/07/22.
//

#ifndef INGR_ONLINE_PRODOTTI_H
#define INGR_ONLINE_PRODOTTI_H
#include "categories.h"


class Products {
public:
  static int add_Product(string name, string description, int IDCat);
  static int select_all_Product(int IDcat=0);
  static int callback(void *NotUsed, int argc, char **argv, char **azColName);
  static int update_Product(int prodID, string name, string description, int IDcat);
  static int delete_Product(int prodID);
  static int select_one_Product(int prodID);
};


#endif //INGR_ONLINE_PRODOTTI_H
