// No14.cpp : Defines the entry point for the console application.
//
/*

Write a function to find the longest common prefix string amongst an array of strings.

*/
#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		if (strs.size() == 0) return string();
		if (strs.size() == 1) return strs[0];

		string ret = strs[0];
		
		for (size_t j = 0; j < ret.length(); ++j)
		{
			char curChar = ret[j];
			for (size_t i = 1; i < strs.size(); ++i)
			{
				if (curChar != strs[i][j])
					return ret.substr(0, j);
			}


		}

		return ret;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	Solution so;
	vector<string> strs;
	strs.push_back("abcsdafwafa");
	strs.push_back("abc23131231");
	strs.push_back("abchhhhhhh");
	cout << so.longestCommonPrefix(strs);
	return 0;
}

//solution: very simple solution, compare the char from the beginning to end, whenever you find a dismatch, return the current compared string.

//PS: if strs are empty, return an empty string, if strs only has one string, return the first string