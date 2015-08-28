// No13.cpp : Defines the entry point for the console application.
//

/*

Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.


*/

//https://en.wikipedia.org/wiki/Roman_numerals

#include "stdafx.h"
#include <string>
#include <iostream>

using namespace std;
/*
class Solution {
public:
	int romanToInt(string s) {
		int ret = 0;
		size_t len = s.length();
		char currentChar, nextChar;
		for (size_t i = 0; i < len; ++i)
		{
			currentChar = s[i];
			switch (currentChar)
			{
			case 'I':
				nextChar = getNextChar(i, s);
				if (nextChar != -1)
				{
					switch (nextChar)
					{
					case 'V':
						ret += -1 + 5;
						++i;
						break;
					case 'X':
						ret += -1 + 10;
						++i;
						break;
					default:
						ret += 1;
						break;
					}
				}
				else
					ret += 1;

				break;
			case 'X':
				nextChar = getNextChar(i, s);
				if (nextChar != -1)
				{
					switch (nextChar)
					{
					case 'L':
						ret += -10 + 50;
						++i;
						break;
					case 'C':
						ret += -10 + 100;
						++i;
						break;
					default:
						ret += 10;
						break;
					}
				}
				else
					ret += 10;

				break;
			case 'C':
				nextChar = getNextChar(i, s);
				if (nextChar != -1)
				{
					switch (nextChar)
					{
					case 'D':
						ret += -100+ 500;
						++i;
						break;
					case 'M':
						ret += -100 + 1000;
						++i;
						break;
					default:
						ret += 100;
						break;
					}
				}
				else
					ret += 100;

				break;
			case 'V':
				ret += 5;
				break;
			case 'L':
				ret += 50;
				break;
			case 'D':
				ret += 500;
				break;
			case 'M':
				ret += 1000;
				break;
			default:
				break;
			}
		}
		return ret;
	}


	char getNextChar(size_t idx, string s)
	{
		if (idx < s.length() - 1)
			return s[idx + 1];
		else
			return -1;
	}
};
*/

class Solution {
public:
	int romanToInt(string s) {
		size_t len = s.length();
		int nums[128];
		nums['I'] = 1;
		nums['V'] = 5;
		nums['X'] = 10;
		nums['L'] = 50;
		nums['C'] = 100;
		nums['D'] = 500;
		nums['M'] = 1000;
		int ret = 0;
		for (size_t i = 0; i < len; ++i)
		{
			if (i + 1 < len && nums[s[i + 1]] > nums[s[i]])
				ret -= nums[s[i]];
			else
				ret += nums[s[i]];
		}
		return ret;
	}
 
};
int _tmain(int argc, _TCHAR* argv[])
{
	Solution so;
	cout << so.romanToInt("MMXIV");
	return 0;
}

//solution: so my solution is following the explanations of Roman numberals in wikipedia, which ask for:
//I placed before V or X indicates one less, so four is IV(one less than five) and nine is IX(one less than ten)
//X placed before L or C indicates ten less, so forty is XL(ten less than fifty) and ninety is XC(ten less than a hundred)
//C placed before D or M indicates a hundred less, so four hundred is CD(a hundred less than five hundred) and nine hundred is CM(a hundred less than a thousand)[5]

//so if you put IM into s, it will read as 1001 not 999, because I can only be -1 before V and X

//2nd solution:
//much shorter, use an array as the lookup table, use [' '] as index, the tricky part is , it compares the next value, see if it's greater than current value, if it is, current value will be negative.
//most important: it's faster only compare the next char value, than using switch 
//PS: so the "IM" will be 999, I don't know if it's correct to write "IM" because I can only follows with V or X ?

