#include <iostream>
#include "sqlite3.h"
#include <cgicc/Cgicc.h> 
using namespace cgicc;
using namespace std;

char* err;

void DropTable(sqlite3* db, string tablename) {
	string query = "DROP TABLE " + tablename;
	int res = sqlite3_exec(db, query.c_str(), NULL, NULL, &err);
	if (res != SQLITE_OK) cout << "Insert error: " << err;
	else cout << "<h1>Table dropped successfully!</h1>";
}

int main() {
	cout << "Content-type:text/html\r\n\r\n";
	sqlite3* db;
	sqlite3_open("DB.db", &db);
	int res = sqlite3_exec(db, "CREATE TABLE IF NOT EXISTS Books(BookName varchar(100), Author varchar(100), Year int, Pages int);", NULL, NULL, &err);
	if (res != SQLITE_OK) cout << "Error: " << err << endl;
	res = sqlite3_exec(db, "CREATE TABLE IF NOT EXISTS Authors(Name varchar(100), Surname varchar(100), Birthday varchar(100));", NULL, NULL, &err);
	if (res != SQLITE_OK) cout << "Error: " << err << endl;
	try {
		Cgicc cgi;
		const_form_iterator iter;
		DropTable(db, cgi.getElements().begin()->getName());
	}
	catch (exception& e) {
		cout << e.what() << endl;
	}
}