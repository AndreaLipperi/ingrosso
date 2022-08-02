//
// Created by Matilde Tarchi on 02/08/22.
//

#include "prodotti.h"
#include "categorie.h"


Prodotti::Prodotti(char nome, char desc, char n_c) : Categorie(n_c), nome(nome), desc(desc)  {
}