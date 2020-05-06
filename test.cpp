#include "HAASH.h"
#include <iostream>
#include <sstream>
#include <map>
#include <cassert>
using namespace std;
int main(int argc, char *argv[]){

	HAASH haash;
	std::stringstream ss;
	std::map<std::string, std::string> test_case;
  	test_case[""] = haash.hash("");
	test_case["0"] = haash.hash("0");
	test_case["00"] = haash.hash("00");
	test_case["a"] = haash.hash("a");
	test_case["aa"] = haash.hash("aa");
	test_case["ab"] = haash.hash("ab");
	test_case["Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.ab"] = haash.hash("Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.");
	map<std::string, std::string>::iterator it;
       for (it = test_case.begin(); it != test_case.end(); it++)
       {
            std::cout << "Input: " << it->first << " \nOutput: " << it->second << '\n';
       }
	return 0;
}

