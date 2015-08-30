// No27.cpp : Defines the entry point for the console application.
//

/*
Given an array and a value, remove all instances of that value in place and return the new length.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.
*/
#include "stdafx.h"
#include <vector>
#include <iostream>

using namespace std;
class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		if (nums.size() == 0)
			return 0;

		int count = 0;
		for (size_t i = 0; i < nums.size(); ++i)
		{
			if (val != nums[i])
			{
				nums[count] = nums[i];
				count++;
			}
		}
		return count;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> nums = { 3,3,3};
	Solution so;
	cout << "length = " << so.removeElement(nums,3);
	return 0;
}

//solution: swap numbers! 
//go through all the numbers from the begging to the last non-val number, if you find a val from front, swap with the end non-val number

//solution 2: move all non-val to front, and count how many you have stored in the front! 

//either way you need to go through the vector once.