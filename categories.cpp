//
// Created by Matilde Tarchi on 02/08/22.
//

#include "categories.h"
#include <iostream>
#include "function_db.h"
#include <string>
#include <sqlite3.h>

using namespace std;
//funzione per stampare le select
int Categories::callback(void *NotUsed, int argc, char **argv, char **azColName) {
  function_db *callback;
  callback->callback(&NotUsed,argc,*&argv,*&azColName);
  return 0;
}

int Categories::add_Categories(std::string name) {
  // Pointer to SQLite connection
  sqlite3 *db;

  // Save any error messages
  char *zErrMsg = 0;

  // Save the result of opening the file
  int rc;

  // Save any SQL
  string sql;

  function_db *function;
  function->open(&db,&zErrMsg);

  sql = "INSERT INTO Categories ('Name') VALUES ('"+name+"');";
  // Run the SQL (convert the string to a C-String with c_str() )

  rc = sqlite3_exec(db, sql.c_str(), Categories::callback, 0, &zErrMsg);

  // Close the SQL connection
  sqlite3_close(db);

  return 0;
}

int Categories::select_Categories() {
  // Pointer to SQLite connection
  sqlite3 *db;

  // Save any error messages
  char *zErrMsg = 0;

  // Save the result of opening the file
  int rc;

  // Save any SQL
  string sql;

  function_db *function;
  function->open(&db,&zErrMsg);


  // select sql data

  sql = "SELECT * FROM 'Categories';";
  // Run the SQL (convert the string to a C-String with c_str() )

  rc = sqlite3_exec(db, sql.c_str(), Categories::callback, 0, &zErrMsg);

  // Close the SQL connection
  sqlite3_close(db);

  return 0;
}

int Categories::update_Categories(int CatID, string name) {
  // Pointer to SQLite connection
  sqlite3 *db;

  // Save any error messages
  char *zErrMsg = 0;

  // Save the result of opening the file
  int rc;

  // Save any SQL
  string sql;

  function_db *function;
  function->open(&db,&zErrMsg);

  //query to upadate categories name
  sql="UPDATE Categories SET Name = '"+name+"' WHERE CatID = "+ to_string(CatID)+";";

  // Run the SQL (convert the string to a C-String with c_str() )

  rc = sqlite3_exec(db, sql.c_str(), Categories::callback, 0, &zErrMsg);

  // Close the SQL connection
  sqlite3_close(db);

  return 0;
}
//funzione momentanea perchè poi essendo la chiave primaria
// di Categories chiave esterna di
//Products potrebbe non funzionare
int Categories::delete_Categories(int CatID) {
  // Pointer to SQLite connection
  sqlite3 *db;

  // Save any error messages
  char *zErrMsg = 0;

  // Save the result of opening the file
  int rc;

  // Save any SQL
  string sql;

  function_db *function;
  function->open(&db,&zErrMsg);

  //query to upadate categories name
  sql="Delete from Categories WHERE CatID = "+ to_string(CatID)+";";

  // Run the SQL (convert the string to a C-String with c_str() )

  rc = sqlite3_exec(db, sql.c_str(), Categories::callback, 0, &zErrMsg);

  // Close the SQL connection
  sqlite3_close(db);

  return 0;
}