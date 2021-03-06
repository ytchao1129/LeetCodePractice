#include "pch.h"
#include <iostream>
#include <string>
using namespace std;

int lengthOfLongestSubstring(string s) {

	string temp;

	int max = 0;
	size_t tempi = 0;
	for (size_t i = 0; i < s.size(); i++)
	{
		if (temp.find(s[i]) == temp.npos)
		{
			temp += s[i];
			continue;
		}
		tempi += temp.find(s[i]);
		i = tempi;
		tempi++;

		if (temp.size() > max)
		{
			max = temp.size();
		}
		temp.clear();
	}

	if (temp.size() > max)
	{
		max = temp.size();
	}

	return max;
}

int main()
{
	string input = "abcabcbb";
	int answer = lengthOfLongestSubstring(input);
	cout << input << ",answer:" << answer;
}