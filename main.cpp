#include <iostream>
#include "Server.h"

/*
Installing SQLiteCpp (vcpkg)
Alternatively, you can build and install SQLiteCpp using vcpkg dependency manager:

git clone https://github.com/Microsoft/vcpkg.git
cd vcpkg
./bootstrap-vcpkg.sh
./vcpkg integrate install
./vcpkg install sqlitecpp
*/

using namespace std;

int main() {
	Server f("test");
	cout << "daun";
}