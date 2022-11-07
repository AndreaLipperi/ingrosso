#include <iostream>
#include <stdio.h>
#include <string>
#include <sqlite3.h>
#include "users.h"
#include "categories.h"

#include "products.h"
using namespace std;

int main() {

 string type,business_name, city, address,
      email, psw, user_name, nameProd, descProd, nameCat;
 int CatID, prodID, accesso;
  int query;

 printf("MENU'\n");
 printf("1. accedi\n");
 printf("2. registrati\n");
 printf("Scelta: ");
 scanf("%d", &accesso);
 getchar();
 switch (accesso) {
 case 1:
   cout << "inserire dati utente per accedere\n";
   cout << "Email: \n";
   cin >> email;
   cout << "Password: \n";
   cin >> psw;
   query = Users::access_Users(email,psw);
   break;
 case 2:
   cout << "inserire dati utente per registrarsi\n";
   cout << "Tipo: (F per fornitore, C per cliente) \n";
   cin >> type;
   cout << "Business Name: \n";
   cin >> business_name;
   cout << "Città: \n";
   cin >> city;
   cout << "Indirizzo: \n";
   cin >> address;
   cout << "Email: \n";
   cin >> email;
   cout << "Password: \n";
   cin >> psw;
   cout << "Username: \n";
   cin >> user_name;
   query = Users::add_Users(type, business_name, city, address, email, psw, user_name);
   break;
 }


  if (query==1) {
    int scelta;

    printf("MENU'\n");
    printf("1. inserire prodotto\n");
    printf("2. modificare prodotto\n");
    printf("3. eliminare prodotto\n");
    printf("4. vedere tutti i prodotti di una categoria\n");
    printf("5. inserire categoria prodotti\n");
    printf("6. modificare categoria prodotti\n");
    printf("7. eliminare categoria prodotti\n");
    printf("8. vedere categorie prodotti\n");
    printf("9. modificare password\n");
    printf("10. elimina account\n");
    printf("Scelta: ");
    scanf("%d", &scelta);
    getchar();
    switch (scelta) {
    case 1:
      cout << "Queste sono le categorie disponibili\n";
      Categories::select_all_Categories();
      cout << "inserire dati prodotto\n";
      cout << "Nome prodotto";
      cin >> nameProd;
      cout << "Descrizione prodotto\n";
      cin >> descProd;
      cout << "Categoria prodotto\n";
      cin >> CatID;
      Products::add_Product(nameProd, descProd, CatID);
      break;
    case 2:
      cout << "inserire codice prodotto da modificare\n";
      cin >> prodID;
      cout << "Queste sono i dati del prodotto\n";
      Products::select_one_Product(prodID);
      cout << "inserire nuovi dati prodotto\n";
      cout << "Nome prodotto\n";
      cin >> nameProd;
      cout << "Descrizione prodotto\n";
      cin >> descProd;
      cout << "Categoria prodotto\n";
      cin >> CatID;
      Products::update_Product(prodID, nameProd, descProd, CatID);
      break;
    case 3:
      cout << "Queste sono le categorie disponibili\n";
      Categories::select_all_Categories();
      cout << "indicare la categoria della quale vedere i prodotti\n";
      cin >> CatID;
      cout << "Questi sono i prodotti per quella categoria\n";
      Products::select_all_Product(CatID);
      cout << "indicare il codice del prodotto da eliminare\n";
      cin >> prodID;
      Products::delete_Product(prodID);
      break;
    case 4:
      cout << "Queste sono le categorie disponibili\n";
      Categories::select_all_Categories();
      cout << "indicare la categoria della quale vedere i prodotti\n";
      cin >> CatID;
      cout << "Questi sono i prodotti per quella categoria\n";
      Products::select_all_Product(CatID);
      break;
    case 5:
      cout << "inserire dati categoria\n";
      cout << "Nome categoria";
      cin >> nameCat;
      Categories::add_Categories(nameCat);
      break;
    case 6:
      cout << "inserire codice categoria da modificare\n";
      cin >> CatID;
      cout << "Queste sono i dati della categoria\n";
      Categories::select_one_Categories(CatID);
      cout << "inserire nuovi dati categoria\n";
      cout << "Nome categoria";
      cin >> nameCat;
      break;
    case 7:
      cout << "Queste sono le categorie disponibili\n";
      Categories::select_all_Categories();
      cout << "indicare il codice della categoria da cancellare\n";
      cin >> CatID;
      Categories::delete_Categories(CatID);
      break;
    case 8:
      cout << "Queste sono le categorie disponibili\n";
      Categories::select_all_Categories();
      break;
    case 9:
      cout << "inserire proprio Business Name:\n";
      cin >> business_name;
      cout << "inserire nuova password\n";
      cin >> psw;
      Users::update_Password(business_name,psw);
      break;
    case 10:
      cout << "inserire proprio Business Name:\n";
      cin >> business_name;
      Users::delete_Users(business_name);
      break;
    default:
      printf("Scelta non consentita.\n");
      break;
    }
  }


  /*cout << "Id categoria da cancellare: \n";
  cin >> CatID;
  Categories::delete_Categories(CatID);
  Categories::select_Categories();*/
  //Products::select_Product(3);

 return 0;
}
