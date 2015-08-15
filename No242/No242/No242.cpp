// No242.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

/*
Given two strings s and t, write a function to determine if t is an anagram of s.

For example,
s = "anagram", t = "nagaram", return true.
s = "rat", t = "car", return false.

Note:
You may assume the string contains only lowercase alphabets.
*/

#include <string>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

class Solution {
public:
	bool isAnagram(string s, string t) {
		int alphabetS[26] = { 0 };
		int alphabetT[26] = { 0 };
		for (auto c : s)
			alphabetS[c - 'a'] ++;

		for (auto c : t)
			alphabetT[c - 'a'] ++;

		return memcmp(alphabetS, alphabetT, 26 * sizeof(int)) == 0;
	}
};

//solution:
//count how many letters for all 26 alphabet letters, compare if the numbers are the same 
//PS : memcmp(alphabetS, alphabetT, 26 * sizeof(int)) == 0; is easier than compare the int values one by one