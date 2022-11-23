#include <iostream>
#include "SQLiteCpp/SQLiteCpp.h"

using namespace std;

class Database {

private:
    SQLite::Database mDb;    ///< Database connection
    SQLite::Statement mQuery;

public:
	
	//SQLite::Database getDb() { return mDb; }
	//SQLite::Statement getQuery(); { return mQuery(); }
	
	string getDbName() { return mDb.getFilename(); }

    void ListGreaterThan(const int aParamValue)
    {
        std::cout << "ListGreaterThan(" << aParamValue << ")\n";

        // Bind the integer value provided to the first parameter of the SQL query
        mQuery.bind(":min_weight", aParamValue); // same as mQuery.bind(1, aParamValue);

        // Loop to execute the query step by step, to get one a row of results at a time
        while (mQuery.executeStep())
        {
            std::cout << "row (" << mQuery.getColumn(0) << ", \"" << mQuery.getColumn(1) << "\", " << mQuery.getColumn(2) << ")\n";
        }

        // Reset the query to be able to use it again later
        mQuery.reset();
    }

	//SQLite::Statement getQuery() { return mQuery; }
};