#include <iostream>
#include <string>
#include "sqlite3.h"

using namespace std;

char* err;

void AddAuthorDataToTable(sqlite3* db) {
	string name, surname, birthday;
	cout << "Input author name:\n";
	cin >> name;
	cout << "Input author surname:\n";
	cin >> surname;
	cout << "Input birthday:\n";
	cin >> birthday;
	string query = "INSERT INTO Authors VALUES('" + name + '\'' + "," + '\'' + surname + '\'' + "," + '\'' + birthday +'\'' + ");";
	cout << query << "\n";
	int res = sqlite3_exec(db, query.c_str(), NULL, NULL, &err);
	if (res != SQLITE_OK) cout << "Insert error: " << err;
}

void AddBookDataToTable(sqlite3 *db) {
	string book, author;
	int year, pages;
	cout << "Input book name:\n";
	cin >> book;
	cout << "Input author name:\n";
	cin >> author;
	cout << "Input year book:\n";
	cin >> year;
	cout << "Input pages:\n";
	cin >> pages;
	string query = "INSERT INTO Books VALUES('" + book + '\'' + "," + '\'' + author + '\'' + "," + to_string(year) + "," + to_string(pages) + ");";
	cout << query << "\n";
	int res = sqlite3_exec(db, query.c_str(), NULL, NULL, &err);
	if (res != SQLITE_OK) cout << "Insert error: " << err;
}

void DropTable(sqlite3* db, string tablename) {
	string query = "DROP TABLE " + tablename;
	int res = sqlite3_exec(db, query.c_str(), NULL, NULL, &err);
	if (res != SQLITE_OK) cout << "Insert error: " << err;
}

int main() {
	bool isRun = true;
	int choose;
	cout << "Welcome to the CGI Book Library\nLibrary used in this project:\nSQLite3 version: " << sqlite3_version << endl;
	while (isRun) {
		sqlite3* db;
		sqlite3_stmt* stmt;
		sqlite3_open("Test.db", &db);
		int res = sqlite3_exec(db, "CREATE TABLE IF NOT EXISTS Books(BookName varchar(100), Author varchar(100), Year int, Pages int);", NULL, NULL, &err);
		if (res != SQLITE_OK) cout << "Error: " << err;
		res = sqlite3_exec(db, "CREATE TABLE IF NOT EXISTS Authors(Name varchar(100), Surname varchar(100), Birthday int);", NULL, NULL, &err);
		if (res != SQLITE_OK) cout << "Error: " << err;
		cout << "0. Exit\n1. Add new book\n2. Add new author\n3. Show book list\n4. Show author list\n5. Drop Table\nChoose: ";
		cin >> choose;
		string tablename = "";
		switch (choose) {
		case 0: return EXIT_SUCCESS;
			break;
		case 1: AddBookDataToTable(db);
			break;
		case 2: AddAuthorDataToTable(db);
			break;
		case 5:
			cout << "\nInput database table name: ";
			cin >> tablename;
			DropTable(db, tablename);
			break;
		default: return EXIT_FAILURE;
		}
	}
}