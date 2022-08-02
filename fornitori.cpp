//
// Created by Matilde Tarchi on 02/08/22.
//

#include "fornitori.h"
#include "utenti.h"


Fornitori::Fornitori(char cat, char iban, char t, char rag_s, char citta, char via,
                 char n_civ, char email, char psw, char n_ut) :
                 Utenti(t,rag_s,citta,via,
                        n_civ,email,psw,n_ut), categoria(cat),iban(iban)  {
}