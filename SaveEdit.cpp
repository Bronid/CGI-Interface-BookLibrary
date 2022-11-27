#include <iostream>
#include "sqlite3.h"
#include <cgicc/Cgicc.h> 
#include <list>

using namespace std;
using namespace cgicc;

char* err;

void UpdateAuthorDataTable(sqlite3* db, string name, string surname, string birthday, string id) {
	string query = "UPDATE Authors SET Name = \"" + name + "\", Surname = \"" + surname + "\", Birthday = \"" + birthday + "\"" + "WHERE AuthorId = " + id + ";";
	int res = sqlite3_exec(db, query.c_str(), NULL, NULL, &err);
	if (res != SQLITE_OK) cout << "Insert error: " << err;
}

void UpdateBookDataTable(sqlite3* db, string book, string author, string year, string pages, string id) {
	string query = "UPDATE Books SET BookName = \"" + book + "\", Author = \"" + author + "\", Year = \"" + year + "\", Pages = \"" + pages + "\"" + "WHERE BookId = " + id + ";";
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
		string id = cgi.getElements().rbegin()->getName();

		for (iter = cgi.getElements().begin(); iter != cgi.getElements().end(); ++iter) TempList.push_back(iter->getValue());
		if (cgi.getElements().begin()->getName() == "Name") {
			string name = TempList.front();
			TempList.pop_front();
			string surname = TempList.front();
			TempList.pop_front();
			string birthday = TempList.front();
			UpdateAuthorDataTable(db, name, surname, birthday, id);
		}
		if (cgi.getElements().begin()->getName() == "BookName") {
			string book = TempList.front();
			TempList.pop_front();
			string author = TempList.front();
			TempList.pop_front();
			string year = TempList.front();
			TempList.pop_front();
			string pages = TempList.front();
			UpdateBookDataTable(db, book, author, year, pages, id);
		}

		cout << "<h1>Data updated!</h1>";
		cout << "<FORM action = \"/cgi-bin/index.cgi\" method = \"post\">\n";
		cout << "<INPUT type = \"submit\" value = \"Back\">\n";
		cout << "</FORM>\n";
	}
	catch (exception& e) {
		cout << "Exception:";
		cout << e.what() << endl;
	}
}