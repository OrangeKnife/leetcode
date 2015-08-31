// No28.cpp : Defines the entry point for the console application.
//

/*

Implement strStr().

Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

*/
#include "stdafx.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;
/*
class Solution {
public:
	int strStr(string haystack, string needle) {
		if (needle.length() == 0)
			return 0;

		int idx = -1;
		for (size_t i = 0; i < haystack.size(); ++i)
		{
			char c = haystack[i];
			if (c == needle[0])
			{
				if (memcmp(haystack.data() + i, needle.data(), needle.size()) == 0)
				{
					idx = i;
					break;
				}
			}
		}
		return idx;
	}
};*/


class Solution {
public:
	int strStr(string haystack, string needle) {
		if (needle.length() == 0)
			return 0;
	
		if (haystack.length() == 0 || haystack.length() < needle.length())
			return -1;

		vector<int> table(2 + needle.size());
		table[0] = -1; table[1] = 0;
		int pos = 2;
		int cnd = 0;
		while (pos < needle.length())
		{
			if (needle[pos - 1] == needle[cnd])
			{
				cnd += 1;
				table[pos] = cnd;
				pos += 1;
			}
			else if (cnd > 0)
			{
				cnd = table[cnd];
			}
			else
			{
				table[pos] = 0;
				pos++;
			}
		}

		int i = 0, m = 0;
		for (; i + m < haystack.size();)
		{
			if (haystack[m + i] == needle[i])
			{
				if (i == needle.length() - 1)
					return m; //match all chars in needle

				i += 1;
			}
			else
			{
				if (table[i] > -1)
				{
					m = m + i - table[i];
					i = table[i];
				}
				else
				{
					//table doesn't record the last possible m and last possible i
					i = 0;
					m += 1;
				}
			}
		 
		}

		return -1;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	Solution so;
	cout << "idx = " << so.strStr("", "cce");
	return 0;
}

//solution: compare the first char and then rest of the needles , it's very slow.
//solution 2: KMP algorithm, faster!
//so the algorithm is about "remember last possible position in haystack and last checked length in needle"
//the table is to remember how many same chars before a char and the offset to rollback the position
//link: https://en.wikipedia.org/wiki/Knuth%E2%80%93Morris%E2%80%93Pratt_algorithm
//I exactly implemented the alogrithm.