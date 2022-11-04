//
// Created by Matilde Tarchi on 02/08/22.
//
#include <iostream>
#include "users.h"
#include "function_db.h"
#include <string>
#include <sqlite3.h>

using namespace std;
int num_result;
//funzione per stampare le select
int Users::callback(void *NotUsed, int argc, char **argv, char **azColName) {
  function_db *callback;
  callback->callback(&NotUsed,argc,*&argv,*&azColName);
  string num = *argv;
  num_result =  stoi(num);
  return 0;
}

int Users::add_Users(std::string type, std::string business_name, std::string city, std::string address, std::string email, std::string psw, std::string user_name) {
  // Pointer to SQLite connection
  sqlite3 *db;

  // Save any error messages
  char *zErrMsg = 0;

  // Save the result of opening the file
  int rc;

  function_db *open;
  open->open(&db,&zErrMsg);

  // Save any SQL
  string sql;



  sql = "INSERT INTO Users ('Type', 'Business_Name', 'City', 'Address', 'Email', 'Psw', 'Username') VALUES ('"+type+"','"+business_name+"', '"+city+"', '"+address+"', '"+email+"', '"+psw+"', '"+user_name+"');";

  // Run the SQL (convert the string to a C-String with c_str() )
  rc = sqlite3_exec(db, sql.c_str(), 0, 0, &zErrMsg);

  sqlite3_close(db);
  return 0;
}
int Users::update_Password(std::string business_name, std::string psw) {
  // Pointer to SQLite connection
  sqlite3 *db;

  // Save any error messages
  char *zErrMsg = 0;

  // Save the result of opening the file
  int rc;

  function_db *open;
  open->open(&db,&zErrMsg);

  // Save any SQL
  string sql;

  sql = "SELECT count(*) AS 'Numero Utenti' FROM 'Users' WHERE Business_Name='"+business_name+"';";
  rc = sqlite3_exec(db, sql.c_str(), Users::callback, 0, &zErrMsg);
  if (num_result==0){
    cout << "utente non esistente, forse business name sbagliato;\n";
  } else {
    sql = "UPDATE Users SET Psw = '"+psw+"' WHERE Business_name = '"+business_name+"';";
    rc = sqlite3_exec(db, sql.c_str(), Users::callback, 0, &zErrMsg);
    cout << "password modificata con successo";
  }

  sqlite3_close(db);
  return 0;
}
