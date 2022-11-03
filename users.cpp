//
// Created by Matilde Tarchi on 02/08/22.
//
#include <iostream>
#include "users.h"
#include "function_db.h"
#include <string>
#include <sqlite3.h>

using namespace std;

/*Users::Users(string t, string b_name, string c, string a,
             string email, string psw, string u_name): type(t), business_name(b_name), city(c), address(a), email(email), psw(psw), user_name(u_name)   {
*/
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



  sql = "INSERT INTO Users ('Type', 'Business_Name', 'City', 'Address', 'Email', 'Psw', 'user_name') VALUES ('"+type+"','"+business_name+"', '"+city+"', '"+address+"', '"+email+"', '"+psw+"', '"+user_name+"');";

  // Run the SQL (convert the string to a C-String with c_str() )
  rc = sqlite3_exec(db, sql.c_str(), 0, 0, &zErrMsg);

  sqlite3_close(db);
}
