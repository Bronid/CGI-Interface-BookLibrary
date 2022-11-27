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
	int res = sqlite3_exec(db, "CREATE TABLE IF NOT EXISTS Books(BookId BIGSERIAL NOT NULL PRIMARY Key, BookName varchar(50), Author varchar(50), Year int, Pages int);", NULL, NULL, &err);
	if (res != SQLITE_OK) cout << "Error: " << err << endl;
	res = sqlite3_exec(db, "CREATE TABLE IF NOT EXISTS Authors(AuthorId BIGSERIAL NOT NULL PRIMARY Key, Name varchar(50), Surname varchar(50), Birthday Date);", NULL, NULL, &err);
	if (res != SQLITE_OK) cout << "Error: " << err << endl;
	try {
		Cgicc cgi;
		const_form_iterator iter;
		DropTable(db, cgi.getElements().begin()->getName());
		cout << "<FORM action = \"/cgi-bin/index.cgi\" method = \"post\">\n";
		cout << "<INPUT type = \"submit\" value = \"Back\">\n";
		cout << "</FORM>\n";
	}
	catch (exception& e) {
		cout << e.what() << endl;
	}
}