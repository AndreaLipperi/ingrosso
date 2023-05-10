//
// Created by Andrea Lipperi on 17/03/23.
//
#include "database.h"
#define TEST
#ifdef TEST
    SQLite::Database db("/Users/matildetarchi/CLionProjects/ingrosso/ingrossodb_test.sqlite");
#else
    SQLite::Database db("/Users/matildetarchi/CLionProjects/ingrosso/ingrossodb.sqlite");
#endif