#include <iostream>
#include "sqlite3.h"
#include <cgicc/Cgicc.h> 
#include <list>

using namespace std;
using namespace cgicc;

char* err;

void AddAuthorDataToTable(sqlite3* db, string name, string surname, string birthday) {
	string query = "INSERT INTO Authors(Name, Surname, Birthday) VALUES('" + name + '\'' + "," + '\'' + surname + '\'' + "," + '\'' + birthday + '\'' + ");";
	int res = sqlite3_exec(db, query.c_str(), NULL, NULL, &err);
	if (res != SQLITE_OK) cout << "Insert error: " << err;
}

void AddBookDataToTable(sqlite3* db, string book, string author, string year, string pages) {
	string query = "INSERT INTO Books(BookName, Author, Year, Pages) VALUES('" + book + '\'' + "," + '\'' + author + '\'' + "," + year + "," + pages + ");";
	int res = sqlite3_exec(db, query.c_str(), NULL, NULL, &err);
	if (res != SQLITE_OK) cout << "Insert error: " << err;
}

int main() {
	cout << "Content-type:text/html\r\n\r\n";
	sqlite3* db;
	sqlite3_open("DB.db", &db);
	try {
		Cgicc cgi;
		const_form_iterator iter;
		list<string> TempList;
		for (iter = cgi.getElements().begin(); iter != cgi.getElements().end(); ++iter) TempList.push_back(iter->getValue());
		if (cgi.getElements().begin()->getName() == "Name") {
			string name = TempList.front();
			TempList.pop_front();
			string surname = TempList.front();
			TempList.pop_front();
			string birthday = TempList.front();
			AddAuthorDataToTable(db, name, surname, birthday);
		}
		if (cgi.getElements().begin()->getName() == "BookName") {
			string book = TempList.front();
			TempList.pop_front();
			string author = TempList.front();
			TempList.pop_front();
			string year = TempList.front();
			TempList.pop_front();
			string pages = TempList.front();
			AddBookDataToTable(db, book, author, year, pages);
		}
		cout << "<h1>New data added!</h1>";

	}
	catch (exception& e) {
		cout << "Exception:";
		cout << e.what() << endl;
	}
}