//
// Created by Matilde Tarchi on 29/07/22.
//

#ifndef INGR_ONLINE_FORNITORI_H
#define INGR_ONLINE_FORNITORI_H
#include "utenti.h"

class Fornitori: public Utenti {
public:
    explicit Fornitori(char cat, char iban, char tipo, char rag_soc,
                       char citta, char via, char num_civ, char email,
                       char psw, char nome_utente);


private:
    char categoria, iban;

};



#endif //INGR_ONLINE_FORNITORI_H
