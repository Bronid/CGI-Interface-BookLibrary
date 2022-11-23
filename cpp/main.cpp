#include <iostream>
#include <string>
#include "sqlite3.h"

using namespace std;

char* err;

static inline string getExamplePath()
{
	string filePath(__FILE__);
	return filePath.substr(0, filePath.length() - std::string("main.cpp").length()) + "databases\\";
}

void AddDataToTable(sqlite3 *db) {
	string book;
	int year, pages;
	cout << "Input book name:\n";
	cin >> book;
	cout << "Input year book:\n";
	cin >> year;
	cout << "Input pages:\n";
	cin >> pages;
	string query = "INSERT INTO Books VALUES('" + book + '\'' + "," + to_string(year) + "," + to_string(pages) + ");";
	cout << query << "\n";
	int res = sqlite3_exec(db, query.c_str(), NULL, NULL, &err);
	if (res != SQLITE_OK) cout << "Insert error: " << err;
}

static const string filename_example_db3 = getExamplePath() + "example.db3";

int main() {
	int choose;
    sqlite3 *db;
    sqlite3_stmt* stmt;
    sqlite3_open("Test.db", &db);
	int res = sqlite3_exec(db, "CREATE TABLE IF NOT EXISTS Books(BookName varchar(100), Year int, Pages int);", NULL, NULL, &err);
	if (res != SQLITE_OK) cout << "Error: " << err;
	cout << "Welcome to the CGI Book Library\nLibrary used in this project:\nSQLite3 version: " << sqlite3_version;
	cout << "Choose:\n0. Exit\n1. Add new book\n";
	cin >> choose;
	switch(choose) {
	case 0: return EXIT_SUCCESS;
		break;
	case 1: AddDataToTable(db);
		break;
	default: return EXIT_FAILURE;
	}
	//Database db(filename_example_db3);
	//db.ListGreaterThan(5);
}