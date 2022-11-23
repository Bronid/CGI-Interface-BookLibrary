#ifndef DB_H
#define DB_H
#include <iostream>
#include "SQLiteCpp/SQLiteCpp.h"

using namespace std;

class Database {

private:
	SQLite::Database mDb;
	SQLite::Statement mQuery;

public:
	Database(string DBpath, string SqlStatement) :
		mDb(DBpath),   // Open a database file in read-only mode
		mQuery(mDb, SqlStatement) {}
	string getDbName();
	void ListGreaterThan(const int aParamValue);
};
#endif