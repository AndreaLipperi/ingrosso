//
// Created by Matilde Tarchi on 29/07/22.
//

#ifndef INGR_ONLINE_PRODOTTI_H
#define INGR_ONLINE_PRODOTTI_H
#include "categories.h"


class Products : public Categories{
public:
    explicit Products(char n, char desc, char c_n);


private:
    char name;
    char desc;

};


#endif //INGR_ONLINE_PRODOTTI_H
