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
int main() {
	cout << "Content-type:text/html\r\n\r\n";
	sqlite3* db;
	sqlite3_stmt* stmt{};
	sqlite3_open("DB.db", &db);
	try {
		Cgicc cgi;
		string datatoedit = cgi.getElements().begin()->getName();
		const char delim = '_';
		list<string> outList;
		tokenize(datatoedit, delim, outList);
		string TableName = outList.front();
		string query = "";
		int tablelength = 0;
		if (TableName == "Books") {
			query = "SELECT * FROM Books WHERE BookId=" + outList.back();
			tablelength = 5;
		}
		if (TableName == "Authors") {
			query = "SELECT * FROM Authors WHERE AuthorId=" + outList.back();
			tablelength = 4;
		}
		sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, 0);
		cout << "<FORM action = \"/cgi-bin/SaveEdit.cgi\" method = \"post\">\n";
		cout << "<P>\n";
		sqlite3_step(stmt);
		for (int i = 1; i < tablelength; i++) cout << sqlite3_column_name(stmt, i) << ": <INPUT type = \"text\" name = \"" << sqlite3_column_name(stmt, i) << "\" value = \"" << sqlite3_column_text(stmt, i) << "\"><BR>\n";
		cout << "<INPUT type = \"submit\" value = \"Confirm\" name = \"" << outList.back() << "\"" << "> <INPUT type = \"reset\" value = \"Reset\">\n";
		cout << "</P>\n";
		cout << "</FORM>\n";

		cout << "<FORM action = \"/cgi-bin/index.cgi\" method = \"post\">\n";
		cout << "<INPUT type = \"submit\" value = \"Back\">\n";
		cout << "</FORM>\n";
	}
	catch (exception& e) {
		cout << "Exception:";
		cout << e.what() << endl;
	}
}