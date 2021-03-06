

#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

// max:2147483647  min:-2147483648

int myAtoi(string s) 
{
	auto sign = '+';
	int idx = 0;
	// remove leading whitespace 
	for (size_t i = 0; i < s.length(); i++)
	{
		if (s[i] == ' ')
		{
			++idx;
			continue;
		}
		break;
	}
	s.erase(0, idx);
	if (s.length() == 0)
	{
		return 0;
	}

	// -, +
	if (s[0] == '+')
	{
		s.erase(0, 1);
	}
	else if (s[0] == '-')
	{
		s.erase(0, 1);
		sign = '-';
	}
	if (s.length() == 0)
	{
		return 0;
	}

	// check start from a number
	if (isdigit(s[0]) == false)
	{
		return 0;
	}

	// get all number
	idx = 0;
	for (size_t i = 0; i < s.length(); i++)
	{
		if (isdigit(s[i]))
		{
			++idx;
			continue;
		}
		break;
	}
	s = sign + s.substr(0, idx);

	try {
		int iResult = stoi(s);
		return iResult;
	}
	catch (std::exception& e) {
		if (sign == '+')
		{
			return 2147483647;
		}
		return -2147483648;
	}

	return 0;
}

int main()
{
    cout << "Hello World!\n"; 

	string str = "2147483648";
	
	auto num = myAtoi(str);

	cout << num << endl;
}
