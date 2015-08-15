// No169.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

//Given an array of size n, find the majority element.The majority element is the element that appears more than ⌊ n / 2 ⌋ times.
//You may assume that the array is non - empty and the majority element always exist in the array.

#include <vector>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

class Solution {
public:
	int majorityElement(vector<int>& nums) {
		int weight = 0;
		int ret;
		for (size_t i = 0; i < nums.size(); ++i)
		{
			if (weight == 0)
			{
				ret = nums[i];
				++weight;
				continue;
			}
				

			if (ret == nums[i])
				++weight;
			else
				--weight;


		}

		return ret;

	}
};

//solution:
//The problem can be reinterpreted as "there is a number in the array appears more than n/2 times, how to find it only go though through once?"
//If the majority number weight 1, non-majority number weight -1, when you traverse the array, whenever your weight > 0, you will get the current majority number (length is your current idx).