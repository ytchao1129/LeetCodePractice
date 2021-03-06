
#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(int x) {

	if (x < 0)
	{
		return false;
	}

	auto s = to_string(x);

	if (s.length() == 1)
	{
		return true;
	}

	auto leftIndex = 0;
	auto rightIndex = s.length() - 1;

	while (leftIndex >= 0 && rightIndex < s.length())
	{
		if (s[leftIndex] != s[rightIndex])
		{
			return false;
		}
		leftIndex++;
		rightIndex--;
		if (leftIndex < rightIndex)
		{
			continue;
		}
		break;
	}

	return true;
}

int main()
{
    std::cout << "Hello World!\n"; 

	isPalindrome(1000021);
}