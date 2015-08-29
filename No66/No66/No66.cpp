// No66.cpp : Defines the entry point for the console application.
//

/*

Given a non-negative number represented as an array of digits, plus one to the number.

The digits are stored such that the most significant digit is at the head of the list.

*/
#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {

		int carry = 1;
		for (int i = int(digits.size()) - 1; i >= 0; --i)
		{
			int currentDigit = digits[i];
			digits[i] = (digits[i] + carry) % 10; 

			if (currentDigit == 9 && carry == 1)
			{
				carry = 1;
			}
			else
				carry = 0;
		}

		if (carry == 1)
			digits.insert(digits.begin(), 1);

		return digits;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> digits = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
	Solution so;
	for (auto i : so.plusOne(digits))
	{
		cout << i;
	}
	
	return 0;
}

//solution: straight forward:
//use the human thoughts to plus
//do a carry int to calculate the 9 + 1 situation, my solution can do any Plus, not only plusOne

//Mistake: only the currentDigit == 9 and carry == 1, you need to carry to next digit. otherwise, stop carry