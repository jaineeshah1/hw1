/* Write your test code for the ULListStr in this file */

#include <iostream>
#include "ulliststr.h"

using namespace std;


int main(int argc, char* argv[])
{
	ULListStr dat;
	dat.push_back("7");
	dat.push_front("8");
	dat.push_back("9");
	dat.push_back("10");
	dat.push_back("11");
	dat.push_back("12");
	dat.push_back("13");
	dat.push_back("14");
	dat.push_back("15");
	dat.push_back("16");
	dat.push_back("17");
	dat.push_back("18");
	dat.push_back("19"); // new third node
	std::cout << dat.get(0) << " " << dat.get(1) << " " << dat.get(2) << " " << dat.get(12) << std::endl;
	// prints: 8 7 9 19

	std::cout << dat.size() << std::endl;
	// prints 13 since there are 3 strings stored

	ULListStr dat2;
	dat2.push_front("1");
	dat2.push_back("2");
	dat2.push_front("3");
	dat2.push_front("4");
	dat2.push_front("5");
	dat2.push_front("6");
	dat2.push_front("7");
	dat2.push_front("8");
	dat2.push_front("9");
	dat2.push_front("10");
	dat2.push_front("11");
	dat2.push_front("-1");
	
	std::cout << dat2.get(0) << " " << dat2.get(10) << " " << dat2.get(11) << std::endl;
	// prints: -1 1 2

	dat2.set(10, "new");
	std::cout << dat2.get(0) << " " << dat2.get(10) << " " << dat2.get(11) << std::endl;
	// prints: -1 new 2

	dat2.pop_back();
	dat2.pop_back();
	std::cout << dat2.back() << std::endl;
	// prints: 3

	dat2.pop_front();
	dat2.pop_front();
	std::cout << dat2.front() << std::endl;
	// prints: 10
	
	ULListStr dat3;
	dat3.push_back("7");
	dat3.pop_front();
	std::cout << dat3.size() << std::endl;
	// prints 0 

	ULListStr dat4;
	dat4.push_back("7");
	dat4.pop_back();
	std::cout << dat4.size() << std::endl;
	// prints 0 
	

	return 0;
}
