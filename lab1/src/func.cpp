#include "TLink.h"
#include "TList.h"
#include "TStack.h"
#include "func.h"
#include <iostream>
#include <map>
#include <string>
using namespace std;

int st::prioretet(char a)
{
	switch (a)
	{
	case '(':
		return 1;
		break;
	case '+':
		return 2;
		break;
	case '-':
		return 2;
		break;
	case '*':
		return 3;
		break;
	case '/':
		return 3;
		break;
	}
	return 0;
}


string st::correct(string s)
{
	int count1 = 0; 
	int count2 = 0;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == ' ')
		{
			s.erase(i, 1);
		}
		if (islower(s[i]))
		{
			s[i] = toupper(s[i]);
		}
		if (s[i] == '(')
			count1++;
		if (s[i] == ')')
			count2++;
	}
	if (count1 != count2)
	{
		throw "Check the number of parentheses";
	}
	return s;
}



string st::postfix_form(string s)
{
	TStack<char> stack1;
	TStack<char> stack2;
	char top;
	int m = s.length();
	cout << s << endl;
	for (int i = 0; i < m; i++)
	{
		if ((s[i] >= 'A') && (s[i] <= 'Z'))
		{
			stack1.Push(s[i]);
			continue;
		}
		if (s[i] == '(')
		{
			stack2.Push(s[i]);
			continue;
		}
		if (s[i] == ')')
		{
			while ((top = stack2.Pop()) != '(')
			{
				stack1.Push(top);
			}
			continue;
		}
		if (!stack2.IsEmpty())
		{
			top = stack2.Pop();
			if (prioretet(s[i]) > prioretet(top))
			{
				stack2.Push(top);
				stack2.Push(s[i]);
				continue;
			}
			else
			{
				stack2.Push(top);
				top = stack2.Pop();
				stack2.Push(top);
				while ((prioretet(top) >= prioretet(s[i])) && (!stack2.IsEmpty()))
				{
					stack2.Pop();
					stack1.Push(top);
					if (stack2.IsEmpty()) break;
					top = stack2.Pop();
					stack2.Push(top);
				}
				stack2.Push(s[i]);
				continue;
			}
		}
		else
		{
			stack2.Push(s[i]);
			continue;
		}
	}
	while (!stack2.IsEmpty())
	{
		char a = stack2.Pop();
		stack1.Push(a);
	}
	s = "";
	while (!stack1.IsEmpty())
	{
		char a = stack1.Pop();
		s = a + s;
	}
	cout << "Postfix form:" << endl;
	cout << s << endl;
	return s;
}


float st::calculations(string s)
{
	map<char, float> values = readvalue(s);
	TStack<float> stack;
	int m = s.length();
	float x, y, Result;
	for (int i = 0; i < m; i++)
	{
		if ((s[i] >= 'A') && (s[i] <= 'Z'))
		{
			stack.Push(values[s[i]]);
		}
		if (s[i] == '+')
		{
			x = stack.Pop();
			y = stack.Pop();
			Result = y + x;
			stack.Push(Result);
		}
		if (s[i] == '-')
		{
			x = stack.Pop();
			y = stack.Pop();
			Result = y - x;
			stack.Push(Result);
		}
		if (s[i] == '*')
		{
			x = stack.Pop();
			y = stack.Pop();
			Result = y * x;
			stack.Push(Result);
		}
		if (s[i] == '/')
		{
			x = stack.Pop();
			y = stack.Pop();
			if (x == 0)
			{
				throw "Devision by zero";
			}
			Result = y / x;
			stack.Push(Result);
		}
	}
	Result = stack.Pop();
	return Result;
}

map<char,float> st::readvalue(const string&s)
{
	map<char, float> OpValue;
	float value;
	for (const char& c : s)
	{
		if ((c >= 'A') && (c <= 'Z'))
		{
			if (OpValue.count(c) == 0)
			{
				cout << "Input:" << c << endl;
				cin >> value;
				OpValue[c] = value;
			}
		}
	}
	return OpValue;
}