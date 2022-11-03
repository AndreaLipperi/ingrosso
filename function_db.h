//
// Created by Andrea Lipperi on 03/11/22.
//

#ifndef INGROSSO_DB_DB_FUNCTION_DB_H
#define INGROSSO_DB_DB_FUNCTION_DB_H

#include <sqlite3.h>
class function_db {
public:
  void open(sqlite3 **db, char **zErrMsg);
  int callback(void *NotUsed, int argc, char **argv, char **azColName);

};

#endif // INGROSSO_DB_DB_FUNCTION_DB_H
