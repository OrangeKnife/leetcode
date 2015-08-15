// No58.cpp : Defines the entry point for the console application.
//


//Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.
//If the last word does not exist, return 0.

#include "stdafx.h"

#include <string>

using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

class Solution {
public:
	int lengthOfLastWord(string s) {
		int length = s.length();
		int wordLength = 0;
		for (int i = length - 1; i >= 0; --i)
		{
			if (*(s.c_str() + i) == ' ' && wordLength > 0)
				return wordLength;

			if (*(s.c_str() + i) != ' ')
				++wordLength;
		}

		return wordLength;

	}
};

//solution:
//the problem is to look for the last word length in the s
//search from the end, keep track for the word length if current char is not ' ', once you hit the ' ', return the word length.
//PS1 : the end may be a ' ', so ignore any ' ' if your current word length is 0, which means you don't even find a word.

