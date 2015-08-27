// No8.cpp : Defines the entry point for the console application.
//
/*

Implement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.

Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.

Update (2015-02-10):
The signature of the C++ function had been updated. If you still see your function signature accepts a const char * argument, please click the reload button  to reset your code definition.

spoilers alert... click to show requirements for atoi.

Requirements for atoi:
The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.

The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.

If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.

If no valid conversion could be performed, a zero value is returned. If the correct value is out of the range of representable values, INT_MAX (2147483647) or INT_MIN (-2147483648) is returned.

*/
#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;
class Solution {
public:
	int myAtoi(string str) {
		size_t len = str.length();
		int ret = 0;
		bool positive = true;
		size_t startIdx = 0;
		while (str[startIdx] == ' ')
			startIdx++;
		
		if (str[startIdx] == '+' || str[startIdx] == '-')
		{
			positive = !(str[startIdx] == '-');
			++startIdx;
		}

		for (size_t i = startIdx; i < len; ++i)
		{
			
			if (str[i] >= '0' && str[i] <= '9')
			{

				if (positive)
				{
					if (ret  > (INT_MAX - (str[i] - '0')) / 10)
						return INT_MAX;
					ret = ret * 10 + str[i] - '0';
				}
				else
				{
					if (ret  < (INT_MIN + (str[i] - '0')) / 10)
						return INT_MIN;
					ret = -(-ret * 10 + str[i] - '0');
				} 			
			}
			else
				return ret;
		}


		return ret;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	Solution so;
	std::cout << so.myAtoi("  -0012a42");
	return 0;
}

//solution: make sure you can recognize the '+' and '-', because when you consider INT_MAX and INT_MIN, you have to deal with them separately. This solution is very similar to No7, this time, we need
//to read from left to right, one digit by one digit, ret = ret * 10 then add the digit to ret value 
//positive value: ret = ret * 10 + digit
//negative value: ret = ret = -(-ret * 10 + str[i] - '0'); you can see I use -ret*10 to make the value positive and later -(...) make it nativate.
//PS: I check the overflow problem based on the boolean 'positive', and return INT_MAX or INT_MIN separately.

//I did this problem right after finished No7, No7 gave me a lot of ideas and edge cases concerns. :D