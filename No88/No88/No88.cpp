// No88.cpp : Defines the entry point for the console application.
//
/*
Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

Note:
You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2. The number of elements initialized in nums1 and nums2 are m and n respectively.
*/
#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;
//class Solution {
//public:
//	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
//		int i = 0;
//		nums1.erase(nums1.begin() + m, nums1.end());
//
//		if (m == 0)
//		{
//			for (int sz = 0; sz < n; ++sz)
//			{
//				nums1.push_back(nums2[sz]);
//			}
//
//			return;
//		}
//
//		for (int j = 0; j < n; )
//		{
//			for (; i < nums1.size() && j < nums2.size();)
//			{
//				if (nums2[j] < nums1[i])
//				{
//					nums1.insert(nums1.begin() + i, nums2[j]);
//					++j;
//				}
//				
//				++i;
//			}
//
//			if (i >= nums1.size() - 1 && j < n)
//			{
//				for (;j<n;)
//				{
//					nums1.insert(nums1.begin() + i++, nums2[j++]);
//				}
//				
//			}
//		}
//	}
//};
class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int i = m - 1;
		int j = n - 1;
		int k = m + n - 1;
		while (i >= 0 && j >= 0)
		{
			if (nums1[i] > nums2[j])
			{
				nums1[k--] = nums1[i--];
			}
			else
			{
				nums1[k--] = nums2[j--];
			}

			
		}

		while (j >= 0)
		{
			nums1[k--] = nums2[j--];
		}
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> nums1 = { 0, 0, 3, 0, 0, 0, 0, 0, 0 };
	vector<int> nums2 = { -1, 1, 1, 1, 2, 3};
	Solution so;
	so.merge(nums1,3,nums2,6);
	return 0;
}

//solution 1: so this solution cost me a lot of time, first, remove the useless elements in the nums1, then for every n elements in the nums2, find the location and insert into
//nums1, last, attach all the elements left in nums2 when run out of nums1
//because using insert will change the size of the vector, need to be very careful about the iterator!

//solution 2: it's the same idea, compare the nums1 and nums2, but move the bigger number to other location, you don;t have to worry about the size of the nums1 or nums2
//think about that! if you have a chance to overwrite some memory and you can keep something stable, do it!
