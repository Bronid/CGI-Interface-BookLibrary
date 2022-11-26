#include <iostream>
#include <array>
#include "sqlite3.h"
#include <cgicc/CgiDefs.h> 
#include <cgicc/Cgicc.h> 
#include <cgicc/HTTPHTMLHeader.h> 
#include <cgicc/HTMLClasses.h>
#include <list>

using namespace std;
using namespace cgicc;

char* err;

void AddAuthorDataToTable(sqlite3* db, string name, string surname, string birthday) {
	string query = "INSERT INTO Authors VALUES('" + name + '\'' + "," + '\'' + surname + '\'' + "," + '\'' + birthday + '\'' + ");";
	int res = sqlite3_exec(db, query.c_str(), NULL, NULL, &err);
	if (res != SQLITE_OK) cout << "Insert error: " << err;
}

void AddBookDataToTable(sqlite3* db, string book, string author, string year, string pages) {
	string query = "INSERT INTO Books VALUES('" + book + '\'' + "," + '\'' + author + '\'' + "," + year + "," + pages + ");";
	int res = sqlite3_exec(db, query.c_str(), NULL, NULL, &err);
	if (res != SQLITE_OK) cout << "Insert error: " << err;
}

void DropTable(sqlite3* db, string tablename) {
	string query = "DROP TABLE " + tablename;
	int res = sqlite3_exec(db, query.c_str(), NULL, NULL, &err);
	if (res != SQLITE_OK) cout << "Insert error: " << err;
}

int main() {
	cout << "Content-type:text/html\r\n\r\n";
	cout << "New information added!";
	sqlite3* db;
	sqlite3_open("Test.db", &db);
	int res = sqlite3_exec(db, "CREATE TABLE IF NOT EXISTS Books(BookName varchar(100), Author varchar(100), Year int, Pages int);", NULL, NULL, &err);
	if (res != SQLITE_OK) cout << "Error: " << err;
	res = sqlite3_exec(db, "CREATE TABLE IF NOT EXISTS Authors(Name varchar(100), Surname varchar(100), Birthday varchar(100));", NULL, NULL, &err);
	if (res != SQLITE_OK) cout << "Error: " << err;
	try {
		Cgicc cgi;
		const_form_iterator iter;
		list<string> TempList;
		for (iter = cgi.getElements().begin(); iter != cgi.getElements().end(); ++iter) TempList.push_back(iter->getValue());
		if (TempList.size() == 3) {
			string name = TempList.front();
			TempList.pop_front();
			string surname = TempList.front();
			TempList.pop_front();
			string birthday = TempList.front();
			AddAuthorDataToTable(db, name, surname, birthday);
		}
		if (TempList.size() == 4) {
			string book = TempList.front();
			TempList.pop_front();
			string author = TempList.front();
			TempList.pop_front();
			string year = TempList.front();
			TempList.pop_front();
			string pages = TempList.front();
			AddBookDataToTable(db, book, author, year, pages);
		}

	}
	catch (exception& e) {
		cout << e.what() << endl;
	}
}