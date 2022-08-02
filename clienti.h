//
// Created by Matilde Tarchi on 29/07/22.
//

#ifndef INGR_ONLINE_CLIENTI_H
#define INGR_ONLINE_CLIENTI_H
#include "utenti.h"


class Clienti:public Utenti{
public:
    explicit Clienti (char t, char rag_s, char citta, char via,
                     char n_civ, char email, char psw, char n_ut);

private:

};


#endif //INGR_ONLINE_CLIENTI_H
