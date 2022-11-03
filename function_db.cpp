//
// Created by Andrea Lipperi on 03/11/22.
//

#include "function_db.h"
#include <iostream>
#include <sqlite3.h>
#include <string>
using namespace std;
void function_db::open(sqlite3 **db, char **zErrMsg) {
  // Save the result of opening the file
  sqlite3_open("/Users/andrealipperi/CLionProjects/ingrosso_online/ingrosso_db.db", db);

  if( sqlite3_open("/Users/andrealipperi/CLionProjects/ingrosso_online/ingrosso_db.db", db) ){
    // Show an error message
    cout << "DB Error: " << sqlite3_errmsg(*db) << endl;
    // Close the connection
    sqlite3_close(*db);
    // Return an error
  }
}
int function_db::callback(void *NotUsed, int argc, char **argv, char **azColName) {
  // int argc: holds the number of results
  // (array) azColName: holds each column returned
  // (array) argv: holds each value

  for(int i = 0; i < argc; i++) {

    // Show column name, value, and newline
    cout << azColName[i] << ": " << argv[i] << endl;

  }
  // Insert a newline
  cout << endl;

  // Return successful
  return 0;
}