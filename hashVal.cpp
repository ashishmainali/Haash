#include "HAASH.h"
#include <iostream>
#include <sstream>

int main(int argc, char *argv[]){

	HAASH haash;
	std::stringstream ss;
	ss << argv[1];
	std::cout << haash.hash(ss.str()) << std::endl;;

	return 0;
}
