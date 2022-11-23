#include <iostream>
#include "../header/Database.h"
#include "sqlite3.h"

using namespace std;

static inline string getExamplePath()
{
	string filePath(__FILE__);
	return filePath.substr(0, filePath.length() - std::string("main.cpp").length()) + "databases\\";
}

static const string filename_example_db3 = getExamplePath() + "example.db3";

int main() {
    sqlite3 *db;
    sqlite3_stmt* stmt;
    sqlite3_open("Test.db", &db);
	cout << "Welcome to the CGI Book Library\nLibrary used in this project:\nSQLite3 version: " << SQLITECPP_VERSION;
	const SQLite::Header header = SQLite::Database::getHeaderInfo(filename_example_db3);

    std::cout << "Magic header string: " << header.headerStr << std::endl;
    std::cout << "Page size bytes: " << header.pageSizeBytes << std::endl;
    std::cout << "File format write version: " << (int)header.fileFormatWriteVersion << std::endl;
    std::cout << "File format read version: " << (int)header.fileFormatReadVersion << std::endl;
    std::cout << "Reserved space bytes: " << (int)header.reservedSpaceBytes << std::endl;
    std::cout << "Max embedded payload fraction " << (int)header.maxEmbeddedPayloadFrac << std::endl;
    std::cout << "Min embedded payload fraction: " << (int)header.minEmbeddedPayloadFrac << std::endl;
    std::cout << "Leaf payload fraction: " << (int)header.leafPayloadFrac << std::endl;
    std::cout << "File change counter: " << header.fileChangeCounter << std::endl;
    std::cout << "Database size pages: " << header.databaseSizePages << std::endl;
    std::cout << "First freelist trunk page: " << header.firstFreelistTrunkPage << std::endl;
    std::cout << "Total freelist trunk pages: " << header.totalFreelistPages << std::endl;
    std::cout << "Schema cookie: " << header.schemaCookie << std::endl;
    std::cout << "Schema format number: " << header.schemaFormatNumber << std::endl;
    std::cout << "Default page cache size bytes: " << header.defaultPageCacheSizeBytes << std::endl;
    std::cout << "Largest B tree page number: " << header.largestBTreePageNumber << std::endl;
    std::cout << "Database text encoding: " << header.databaseTextEncoding << std::endl;
    std::cout << "User version: " << header.userVersion << std::endl;
    std::cout << "Incremental vaccum mode: " << header.incrementalVaccumMode << std::endl;
    std::cout << "Application ID: " << header.applicationId << std::endl;
    std::cout << "Version valid for: " << header.versionValidFor << std::endl;
    std::cout << "SQLite version: " << header.sqliteVersion << std::endl;

	//Database db(filename_example_db3);
	//db.ListGreaterThan(5);
}