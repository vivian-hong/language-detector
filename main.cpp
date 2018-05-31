//
// main.cpp -- calls functions and helpers
//	by: Vivian Hong
//	date: 11/18/15
//

#include <iostream>
#include <fstream>
using namespace std;
//#include "trigram.h"
#include "lang.h"
#include "langlist.h"

int main()
{
	string language;
	string fName;
	LanguageList langlist;

	while(cin >> language >> fName){
		langlist.add(language, fName);
	}
	//langlist.print_freq();
	langlist.calculate();
	return 0;
}
