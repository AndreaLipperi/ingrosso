//
// Created by Matilde Tarchi on 29/07/22.
//

#ifndef INGR_ONLINE_UTENTI_H
#define INGR_ONLINE_UTENTI_H


class Utenti {
public:
    explicit Utenti(char tipo, char rag_soc, char citta, char via,
                     char num_civ, char email, char psw, char nome_utente);


private:
    char tipo, rag_soc, citta, via, num_civ,
            email, psw, nome_utente;

};



#endif //INGR_ONLINE_UTENTI_H
