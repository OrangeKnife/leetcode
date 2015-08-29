// No67.cpp : Defines the entry point for the console application.
//

/*

Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".

*/

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	string addBinary(string a, string b) {
		
		string ret;

		int lenA = a.size();
		int lenB = b.size();
		int carry = 0;
		for (int i = lenA - 1, j = lenB - 1; i >= 0 || j >= 0 ; --i, --j)
		{
			int aDigit = i >= 0 ? a[i] - '0' : 0;
			int bDigit = j >= 0 ? b[j] - '0' : 0;

			carry = carry + aDigit + bDigit;
			char currentDigit = char((carry % 2) + '0');
			carry = carry / 2;
			ret.insert(ret.begin(), currentDigit);
			

		}

		if (carry == 1)
			ret.insert(ret.begin(), '1');
		return ret;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	Solution so;
	cout << so.addBinary("1101", "1");
	return 0;
}

//solution: there are 2 tricky parts:
//1) having i,j to iterate the string a and b, from back to front, if i < 0 and j < 0. stop looping
//2) if i or j one of them < 0 , use 0 as the digit to calculate the carry, think of 11010 + 10 means 11010 + 00010

//PS: make sure you iterate all the chars inside both a and b , don't miss any digits !!!

