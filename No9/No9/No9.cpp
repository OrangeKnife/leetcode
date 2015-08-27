// No9.cpp : Defines the entry point for the console application.
//

/*
Determine whether an integer is a palindrome. Do this without extra space.
*/

#include "stdafx.h"
#include <iostream>

using namespace std;
 
/*
class Solution {
public:
	bool isPalindrome(int x) {
		if (x < 0)
			return false;

		int len = 0;
		int y = x;
		while (y > 0)
		{
			y = y / 10;
			++len;
		}

		bool ret = true;
		y = x;
		for (int i = len; i > len / 2; --i)
		{
			int powerOfTen = pow(10, i - 1);
			int leftDigit = x / powerOfTen;
			int rightDigit = y % 10;
			ret = ret && (leftDigit == rightDigit);
			x = x - leftDigit * powerOfTen;
			y = y / 10;
		}

		return ret;
	}
};
*/
class Solution {
public:
	bool isPalindrome(int x) {
		if (x < 0)
			return false;

		int len = 0;
		int y = x;
		while (y > 0)
		{
			int rightDigit = y % 10;
			y = y / 10;
			++len;
		}

		bool ret = true;
		y = x;
		for (int i = len; i > len / 2; --i)
		{
			int leftDigit = x / pow(10, i - 1);
			int rightDigit = y % 10;
			ret = ret && (leftDigit == rightDigit);
			x = x - leftDigit *  pow(10, i - 1);
			y = y / 10;
		}

		return ret;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	Solution so;
	cout << (so.isPalindrome(12321) ? "True": "False");
	return 0;
}

