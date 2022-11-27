#include <iostream>
#include "sqlite3.h"
#include <cgicc/Cgicc.h> 
#include <list>
#include <sstream>
using namespace cgicc;

using namespace std;

char* err;

void tokenize(string const& str, const char delim, list<string>& out)
{
	// construct a stream from the string
	stringstream ss(str);

	string s;
	while (getline(ss, s, delim)) {
		out.push_back(s);
	}
}

void DeleteDataFromTable(sqlite3* db, list<string> outList) {
	string query = "";
	if (outList.front() == "Books") query = "DELETE FROM Books WHERE BookId=" + outList.back() + ";";
	if (outList.front() == "Authors") query = "DELETE FROM Authors WHERE AuthorId=" + outList.back() + ";";
	int res = sqlite3_exec(db, query.c_str(), NULL, NULL, &err);
	if (res != SQLITE_OK) cout << "Insert error: " << err;
}

int main() {
	cout << "Content-type:text/html\r\n\r\n";
	sqlite3* db;
	sqlite3_open("DB.db", &db);
	try {
		Cgicc cgi;
		string datatodelete = cgi.getElements().begin()->getName();
		const char delim = '_';
		list<string> outList;
		tokenize(datatodelete, delim, outList);
		DeleteDataFromTable(db, outList);
		cout << "<h1>Data deleted!</h1>";

		cout << "<FORM action = \"/cgi-bin/index.cgi\" method = \"post\">\n";
		cout << "<INPUT type = \"submit\" value = \"Back\">\n";
		cout << "</FORM>\n";
	}
	catch (exception& e) {
		cout << "Exception:";
		cout << e.what() << endl;
	}
}