//
// Created by Matilde Tarchi on 02/08/22.
//

#include "products.h"
#include "categories.h"
//
// Created by Matilde Tarchi on 02/08/22.
//
#include <iostream>
#include "function_db.h"
#include <string>
#include <sqlite3.h>

using namespace std;
//funzione per stampare le select
int Products::callback(void *NotUsed, int argc, char **argv, char **azColName) {
  function_db *callback;
  callback->callback(&NotUsed,argc,*&argv,*&azColName);
  return 0;
}

int Products::add_Product(std::string name, std::string description, int IDCat) {
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

  sql = "INSERT INTO Products ('Name','Description','IDcat') VALUES ('"+name+"', '"+description+"',"+to_string(IDCat)+");";
  // Run the SQL (convert the string to a C-String with c_str() )

  rc = sqlite3_exec(db, sql.c_str(), Categories::callback, 0, &zErrMsg);

  // Close the SQL connection
  sqlite3_close(db);

  return 0;
}

int Products::select_Product(int IDcat) {
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


  sql = "SELECT count(*) AS 'Numero Prodotti disponibili' FROM 'Product'";
  rc =sqlite3_exec(db, sql.c_str(), Products::callback, 0, &zErrMsg);
  // select sql data
  if (IDcat==0){
    sql = "SELECT Product.IDproduct, Product.Name, Product.Description, Categories.Name FROM 'Product', 'Categories' WHERE IDcat=CatID;";
  } else {

    sql = "SELECT   Product.IDproduct, Product.Name, Product.Description, Categories.Name FROM 'Product', 'Categories' WHERE IDcat = "+ to_string(IDcat)+" AND IDcat=CatID;;";
  }
  // Run the SQL (convert the string to a C-String with c_str() )

  rc = sqlite3_exec(db, sql.c_str(), Products::callback, 0, &zErrMsg);

  // Close the SQL connection
  sqlite3_close(db);

  return 0;
}

int Products::update_Product(int prodID, std::string name, std::string description, int IDcat) {
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
  sql="UPDATE Products SET Name = '"+name+"', Description = '"+description+"', IDcat = "+ to_string(IDcat)+" WHERE IDproduct = "+ to_string(prodID)+";";

  // Run the SQL (convert the string to a C-String with c_str() )

  rc = sqlite3_exec(db, sql.c_str(), Categories::callback, 0, &zErrMsg);

  // Close the SQL connection
  sqlite3_close(db);

  return 0;
}

int Products::delete_Product(int prodID) {
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
  sql="Delete from Products WHERE IDproduct = "+ to_string(prodID)+";";

  // Run the SQL (convert the string to a C-String with c_str() )

  rc = sqlite3_exec(db, sql.c_str(), Categories::callback, 0, &zErrMsg);

  // Close the SQL connection
  sqlite3_close(db);

  return 0;
}
