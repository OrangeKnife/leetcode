// No26.cpp : Defines the entry point for the console application.
//
/*
Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

For example,
Given input array nums = [1,1,2],

Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively. It doesn't matter what you leave beyond the new length.

*/
#include "stdafx.h"
#include <vector>
#include <iostream>

using namespace std;
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.size() == 0)
			return 0;

		int len = 1;
		int lastI = nums[0];
		for (size_t i = 1 ; i < nums.size(); ++i)
		{
			if (nums[i] != lastI)
			{
				nums[len] = nums[i];
				len++;
				lastI = nums[i];
			}
		}
		return len;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> nums = { 1, 1, 2 , 5, 5, 5 ,5,424,424,22424};
	Solution so;
	cout << "new length = " << so.removeDuplicates(nums);
	return 0;
}

//solution : sorted array , so you will get this kind thing: x,x,x,y,y,z,z,z,z...
//so, whenever you find a number is different from last number, copy the value to the len and do a len++; you will keep tracking the len and current available idx for copying