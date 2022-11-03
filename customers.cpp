//
// Created by Matilde Tarchi on 02/08/22.
//

#include "customers.h"
#include <iostream>
#include <string>
#include <sqlite3.h>
#include "users.h"

using namespace std;
/*Customers::Customers(string t, string b_name, string c, string a,
                     string email, string psw, string u_name)  {
}
*/
// Pointer to SQLite connection
sqlite3 *db;

// Save any error messages
char *zErrMsg = 0;

// Save the result of opening the file
int rc;

// Save any SQL
string sql;

// Save the result of opening the file
rc = sqlite3_open("/Users/matildetarchi/CLionProjects/ingrosso_online/ingrosso_db.db", &db);

if( rc ){
// Show an error message
cout << "DB Error: " << sqlite3_errmsg(db) << endl;
// Close the connection
sqlite3_close(db);
// Return an error
}

sql = "INSERT INTO Users ('Type', 'Business_Name', 'City', 'Address', 'Email', 'Psw', 'user_name') VALUES ('"+type+"','"+business_name+"', '"+city+"', '"+address+"', '"+this->email+"', '"+this->psw+"', '"+user_name+"');";

// Run the SQL (convert the string to a C-String with c_str() )
rc = sqlite3_exec(db, sql.c_str(), 0, 0, &zErrMsg);

sqlite3_close(db);
}