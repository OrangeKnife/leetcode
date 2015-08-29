// No70.cpp : Defines the entry point for the console application.
//


/*
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

*/
#include "stdafx.h"
#include <string>
#include <iostream>

using namespace std;
/*
class Solution {
public:
int climbStairs(int n) {
int ret = 1;
for (int i = n - 2; i >= 0; i -= 2)
ret += getCombination(i + (n - i) / 2, (n - i) / 2);

return ret;
}

int getCombination(int n, int m)
{
int ret = 1;
for (int i = n; i > n-m; --i)
ret *= i;

for (int j = m; j > 0; --j)
ret /= j;
return ret;
}
};
*/
class Solution {
public:
	int climbStairs(int n) {
		if (n <= 2)
			return n;

		
		int pre1 = 1;
		int pre2 = 2;
		int steps = pre1 + pre2;

		while (steps <= n)
		{
			int temp = pre1 + pre2;
			pre1 = pre2;
			pre2 = temp;
			steps++;
		}


		return pre2;
	}

 
};

int _tmain(int argc, _TCHAR* argv[])
{
	Solution so;
	cout << so.climbStairs(35);
	return 0;
}

//solution 1: I stuck into a situation that trying to list the combinations of 1 and 2 to reach n, too many calculations
//solution 2: Fibonacci number solution, added the previous 2 numbers to get the next one, why?
//