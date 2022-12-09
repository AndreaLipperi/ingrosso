//
// Created by Matilde Tarchi on 29/07/22.
//

#ifndef INGR_ONLINE_CARRELLO_H
#define INGR_ONLINE_CARRELLO_H

#include "subcategoriesMethods.h"
#include "usersMethods.h"
#include <string>
using namespace std;
class Favourites : public TableUsers, public TableProducts{
public:

    Favourites();
    Favourites(int new_id, int new_quantity, Products *new_prod, const string &new_id_cust, const string &new_id_prov);
    int get_id() {
        return ID;
    }
    int get_quantity() {
        return quantity;
    }
    Products* get_prod(){
        return prod;
    }
    string get_id_cust(){
        return IDcustomer;
    }
    string get_id_prov(){
        return IDprovider;
    }
    string get_prod_name(const string &prod){
        return TableProducts::select_name(prod);
    }
    string get_prov_name(string id_prov) {
        return TableUsers::select_username(id_prov);
    }
    void set_name(int new_quantity){
        Favourites::quantity=new_quantity;
    }
    void set_prod(Products *new_prod){
        Favourites::prod=new_prod;
    }
    void set_IDuser(string new_id_cust){
        Favourites::IDcustomer=new_id_cust;
    }
    void set_IDprov(string new_id_prov){
        Favourites::IDprovider=new_id_prov;
    }

private :
    int ID;
    int quantity;
    Products *prod;
    string IDcustomer;
    string IDprovider;

};

#endif //INGR_ONLINE_CARRELLO_H