//
// Created by Matilde Tarchi on 29/07/22.
//

#ifndef INGR_ONLINE_PRODOTTI_H
#define INGR_ONLINE_PRODOTTI_H
#include "categorie.h"


class Prodotti : public Categorie{
public:
    explicit Prodotti(char nome, char desc, char n_c);


private:
    char nome;
    char desc;

};


#endif //INGR_ONLINE_PRODOTTI_H
