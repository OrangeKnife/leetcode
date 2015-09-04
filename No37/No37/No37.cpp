// No37.cpp : Defines the entry point for the console application.
//


/*
The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string.
*/
#include "stdafx.h"
#include <string>
#include <iostream>

using namespace std;
class Solution {
public:
	string countAndSay(int n) {
		string ret = "1";

		int lastNum = 1;
		int lastNumCount = 0;
		for (int i = 1; i < n; ++i)
		{
			lastNum = ret[0]  - '0';
			lastNumCount = 0;
			string newStr;

			for (int j = 0; j < ret.size(); j++)
			{
				if (ret[j] - '0' == lastNum)
					lastNumCount++;
				
				if ( ret[j] - '0' != lastNum)
				{
					newStr.push_back(lastNumCount + '0'); newStr.push_back(lastNum + '0');
					lastNum = ret[j] - '0';
					lastNumCount = 1;
				}
			}
			
			if (lastNumCount > 0)
			{
				newStr.push_back(lastNumCount + '0'); newStr.push_back(lastNum + '0');
				lastNum = -1;
				lastNumCount = 0;
			}
			ret = newStr;

			
			
		}

		return ret;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	
	Solution so;
	cout << "say:" << so.countAndSay(5);
	return 0;
}

//solution: make a new string every loop, assign the new loop to ret , new string will be generated by iterating chars inside ret, counting how many numbers next to each other.
//PS: last num count means how many numbers already counted, if reach the last char of ret, added the last num count and last num at the end, for finishing the new string

//mistake: I used to check whether or not current char is the last char inside ret, which is not good. make the logic complicated , just move the last check outside j loop, will be easier.