// No17.cpp : Defines the entry point for the console application.
//


/*
iven a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.

1	  2abc 3def
4ghi  5jkl 6mno
7pqrs 8tuv 9wxyz

Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

*/
#include "stdafx.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<string> letterCombinations(string digits) {
		string letterMap[10];
		letterMap[2] = "abc";
		letterMap[3] = "def";
		letterMap[4] = "ghi";
		letterMap[5] = "jkl";
		letterMap[6] = "mno";
		letterMap[7] = "pqrs";
		letterMap[8] = "tuv";
		letterMap[9] = "wxyz";

		vector<string> temp;

		for (size_t i = 0; i < digits.length(); ++i)
		{
			int digit = digits[i] - '0';
			temp = combine(temp, letterMap[digit]);
		}

		return temp;
	}

	vector<string> combine(vector<string> currentStrs, string letters)
	{
		vector<string> ret;
		if (currentStrs.size() == 0)
		{
			for (auto c : letters)
			{
				string aString;
				aString.push_back(c);
				ret.push_back(aString);
			}
		}
		else
		{
			for (auto s : currentStrs)
			{
				for (auto c : letters)
				{
					string aString;
					aString.push_back(c);
					ret.push_back(s + aString);
				}
			}
		}

		return ret;
	}

};


int _tmain(int argc, _TCHAR* argv[])
{
	Solution so;
	for (auto s : so.letterCombinations("23"))
	{
		cout << s <<" " ;
	}
	
	return 0;
}

//solution : solution is straight forward:
//I need a letter map to get those abc def ... from a number , so I made an array of strings
//I need a function to multiply an array of strings by a string, which means xxx, yyy, zzz  multiply abc   =>  xxxa, xxxb, xxxc,  yyya, yyyb, yyyc , zzza, zzzb, zzzc
//so the array get extended, I want to save the array for furture use.
//repeat the process untile all the strings are processed.
//return  the array of strings


//PS: make a letter map easy to use : don't use index 0 and 1
//PS2: make the for loop easy to use : auto c: aString
//PS3: string aString; aString.push_back(c); is very bad :(