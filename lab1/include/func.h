 #ifndef FUNC_H
#define FUNC_H
#include "TLink.h"
#include "TList.h"
#include "TStack.h"
#include <iostream>
#include <map>
#include <string>
using namespace std;
class st
{
public:
	static string postfix_form(string );
	static float calculations(string );
	static string correct(string s);
public:
	static int prioretet(char);
	static map<char, float> readvalue(const string&);
};

#endif