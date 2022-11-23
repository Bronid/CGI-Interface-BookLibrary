#include <iostream>
#include <sql.h>

using namespace std;

class Server {

private:
	string url;

public:
	Server(string _url) {
		url = _url;
	}

};