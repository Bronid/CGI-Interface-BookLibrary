#include <iostream>
#include <array>
#include <cgicc/CgiDefs.h> 
#include <cgicc/Cgicc.h> 
#include <cgicc/HTTPHTMLHeader.h> 
#include <cgicc/HTMLClasses.h>
#include <sqlite3.h>

using namespace std;
using namespace cgicc;

char* err;

void printTable(string TableName, string DataName[], int tablelength) {
	sqlite3* db;
	sqlite3_stmt* stmt{};
	sqlite3_open("Test.db", &db);
	if (TableName == "Books") {
		int res = sqlite3_exec(db, "CREATE TABLE IF NOT EXISTS Books(BookName varchar(100), Author varchar(100), Year int, Pages int);", NULL, NULL, &err);
		if (res != SQLITE_OK) cout << "Error: " << err;
	}
	if (TableName == "Authors") {
		int res = sqlite3_exec(db, "CREATE TABLE IF NOT EXISTS Authors(Name varchar(100), Surname varchar(100), Birthday varchar(100));", NULL, NULL, &err);
		if (res != SQLITE_OK) cout << "Error: " << err;
	}
	cout << "<h2>" + TableName + "</h2>\n";
	cout << "<table>\n";
	cout << "<tr>\n";
	for (int i = 0; i < tablelength; i++) cout << "<th>" + DataName[i] + "</th>\n";
	cout << "</tr>\n";

	if (TableName == "Books") sqlite3_prepare_v2(db, "SELECT BookName, Author, Year, Pages FROM Books", -1, &stmt, 0);
	if (TableName == "Authors") sqlite3_prepare_v2(db, "SELECT Name, Surname, Birthday FROM Authors", -1, &stmt, 0);
	//тут данные на каждую таблицу
	while(sqlite3_step(stmt) != SQLITE_DONE) {
		cout << "<tr>\n";
		for (int i = 0; i < tablelength; i++) cout << "<td>" << sqlite3_column_text(stmt, i) << "</td>\n";
		cout << "</tr>\n";
	}
	cout << "</table>\n";
}

void printCSS() {
	cout << "<style>\n";
	cout << "table, th, td {\n";
	cout << "border: 1px solid black;\n";
	cout << "}\n";
	cout << "</style>\n";
}

int main() {
	string TestData1[] = { "Book Name", "Author", "Year", "Pages" };
	string TestData2[] = { "Name", "Surname", "Birthday" };
	cout << "Content-type:text/html\r\n\r\n";
	cout << "<html>\n";
	printCSS();
	cout << "<head>\n";
	cout << "<title>Book Library</title>\n";
	cout << "</head>\n";
	cout << "<body>\n";
	cout << "<h1>Book Library Page</h1>\n";
	printTable("Books", TestData1, sizeof(TestData1) / sizeof(*TestData1));
	cout << "<FORM action = \"/cgi-bin/AddToDB.cgi\" method = \"post\">\n";
	cout << "<P>\n";
	cout << "Book name: <INPUT type = \"text\" name = \"bookname\"><BR>\n";
	cout << "Author : <INPUT type = \"text\" name = \"author\"><BR>\n";
	cout << "Year : <INPUT type = \"text\" name = \"year\"><BR>\n";
	cout << "Pages : <INPUT type = \"text\" name = \"pages\"><BR>\n";
	cout << "<INPUT type = \"submit\" value = \"Add\"> <INPUT type = \"reset\" value = \"Reset\">\n";
	cout << "</P>\n";
	cout << "</FORM>\n";
	printTable("Authors", TestData2, sizeof(TestData2) / sizeof(*TestData2));
	cout << "<FORM action = \"/cgi-bin/AddToDB.cgi\" method = \"post\">\n";
	cout << "<P>\n";
	cout << "Name : <INPUT type = \"text\" name = \"name\"><BR>\n";
	cout << "Surname : <INPUT type = \"text\" name = \"surname\"><BR>\n";
	cout << "Birthday : <INPUT type = \"text\" name = \"birthday\"><BR>\n";
	cout << "<INPUT type = \"submit\" value = \"Add\"> <INPUT type = \"reset\" value = \"Reset\">\n";
	cout << "</P>\n";
	cout << "</FORM>\n";
	cout << "<br/>\n";
	cout << "</body>\n";
	cout << "</html>\n";
}