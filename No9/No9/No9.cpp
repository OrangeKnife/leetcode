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
		if (x == 0) return true;
		int original = x;
		int result = 0;
		while (x != 0)
		{
			int digit = x % 10;
			if (result >(INT_MAX - digit) / 10)
				return false;
			result = result * 10 + digit;
			x /= 10;
		}
		return result == original;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	Solution so;
	cout << (so.isPalindrome(12321) ? "True": "False");
	return 0;
}

//solution 1: very intuitive: grab the left digit and right digit, compare them. actually , I count the length first , use it in the the loop later, there is another way to do this:
//http://articles.leetcode.com/2012/01/palindrome-number.html
//you will find , in order to get the left digit, the article use a 'div' which is 10000... to match the length of the int.
//this is good because you don't have to do a pow(10,?) for dividing

//second solution: take advantage of reverse int , I did that problem before but I didn't realize it's the same number when you reverse the int.
//so the second solution is just reverse the int and compare the int.
//reversing the int: remember the INT_MAX thing

//PS that article is published in 2012 and 3 years later people still benefit from that :D