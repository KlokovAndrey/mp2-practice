#include "TLink.h"
#include "TList.h"
#include "TStack.h"
#include "func.h"
#include <iostream>
#include <string>
using namespace std;

void main()
{
	string s;
	float Result;
	cout << "Write your expression:" << endl;
	getline(cin, s);
	try
	{
		s = st::correct(s);
	}
	catch (const char*ex)
	{
		cout << endl << ex << endl;
		return;
	}
	s = st::postfix_form(s);
	try
	{
		Result = st::calculations(s);
	}
	catch (const char*ex)
	{
		cout << endl << ex << endl;
		return;
	}
	cout << endl << "The result is:" << endl << Result << endl;
}