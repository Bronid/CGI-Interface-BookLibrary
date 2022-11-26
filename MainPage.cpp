#include <iostream>
#include <array>
#include <cgicc/CgiDefs.h> 
#include <cgicc/Cgicc.h> 
#include <cgicc/HTTPHTMLHeader.h> 
#include <cgicc/HTMLClasses.h>
#include <sqlite3.h>

using namespace std;
using namespace cgicc;

void printTable(string TableName, string DataName[], int tablelength) {
	sqlite3* db;
	sqlite3_open("Test.db", &db);
	cout << "<h2>" + TableName + "</h2>\n";
	cout << "<table>\n";
	cout << "<tr>\n";
	for (int i = 0; i < tablelength; i++) cout << "<th>" + DataName[i] + "</th>\n";
	cout << "</tr>\n";

	//тут данные на каждую таблицу
	for (int j = 0; j < 1; j++) {
		cout << "<tr>\n";
		for (int i = 0; i < tablelength; i++) cout << "<td> test </td>\n";
		cout << "</tr>\n";
	}
	cout << "</table>\n";
	cout << "<button class=\"button button1\">Add</button>";
	cout << "<button class=\"button button2\">Delete</button>\n";
}

void printCSS() {
	cout << "<style>\n";
	cout << "table, th, td {\n";
	cout << "border: 1px solid black;\n";
	cout << "}\n";
	cout << ".button {\n";
	cout << "border: none;\n";
	cout << "color: white;\n";
	cout << "padding: 15px 32px;\n";
	cout << "text-align: center;\n";
	cout << "text-decoration: none;\n";
	cout << "display: inline-block;\n";
	cout << "font-size: 16px;\n";
	cout << "margin: 4px 2px;\n";
	cout << "cursor: pointer;\n";
	cout << "}\n";
	cout << ".button1 {background-color: #32CD32;}\n";
	cout << ".button2 {background-color: #8B0000;}\n";
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