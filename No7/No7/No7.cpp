// No7.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;
/* BAD SOLUTION
class Solution {
public:
	int reverse(int x) {
		if (x == INT_MIN) return 0;
		int len;
		int num[11] = { 0 };
		bool positive = x > 0;
		x = x > 0 ? x : (x * (-1));
		len = 10;
		for (int i = 0; i <= 10; ++i)
		{
			int powoften = pow(10, i + 1);

			num[i] = (x - x / powoften * powoften) / pow(10, i);
			x -= num[i] * pow(10, i);

			if (powoften > x)
			{
				len = i + 1;
				break;
			}

		}


		double ret = 0;
		for (int i = 0; i < len; ++i)
		{
			ret += num[i] * pow(double(10), len - i - 1);
		}

		ret *= positive ? 1 : -1;

		if (ret > pow(2, 31))
			return 0;

		return ret;
	}
};
*/

class Solution {
public:
	int reverse(int x) {
		if (x < 0 && x > INT_MIN) return -reverse(-x);
		int ret = 0;
		while (x > 0)
		{
			int digit = x - x / 10 * 10;
			x = x / 10;
			if (ret > (INT_MAX - digit) / 10)
				return 0;
			ret = ret * 10 + digit;
		}
		return ret;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{

	Solution so;
	cout << so.reverse(1231312);
  	return 0;
}

//my first solution is trying to catch every digit and save them for future use. but when I try to compose the int value, I may have overflow problem.
//after submit 4 times, I think I stuck in the solution I try to approach, which means : fail !!!!!!!!!!!!!!
//
//2nd solution is more direct:
// grab the digit at the end of x, and add it to return value , whenever you have a new digit, return value * 10 and add the new digit to return value
//this still have the overflow problem, so how  to detect the ret > INT_MAX ?
// ret = ret * 10 + digit; this line, when ret * 10 , it is the moment overflow, so before ret * 10, we need to check the value
// as we know ret * 10 + digit > INT_MAX is the same expression as ret * 10 > INT_MAX - digit, is the same as ret > ( INT_MAX - digit ) / 10, so deviding by 10 will not cause overflow
//!!!!!!!!!!!!!!!!
//Here comes the fun part : if feed in INT_MIN as x, I will have either compiler error or run time error , cuz you can't do -INT_MIN for the positive value, signed int value range is -2^31 to 2^31 - 1
//positive absolute number is smaller than negative value!
