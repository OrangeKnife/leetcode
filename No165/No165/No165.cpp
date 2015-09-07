// No165.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>;

using namespace std;
class Solution {
public:
	int compareVersion(string version1, string version2) {
		if (version1.size() == 0 && version2.size() > 0)
			return -1;
		else if (version1.size() > 0 && version2.size() == 0)
			return 1;

		int ret = 0;
		int idx1 = 0, idx2 = 0;
		int last1 = 0, last2 = 0;
		string str1, str2;
		while (idx1 < version1.size() || idx2 < version2.size())
		{
			while (idx1 < version1.size() && version1[idx1] != '.')
				idx1++;

			if (last1 < version1.size())
			{
				str1 = version1.substr(last1, idx1 - last1);
				idx1++;
				last1 = idx1;

			}
			else
				str1 = "";
			
			while (idx2 < version2.size() && version2[idx2] != '.')
				idx2++;

			if (last2 < version2.size())
			{
				str2 = version2.substr(last2, idx2 - last2);
				idx2++;
				last2 = idx2;
			}
			else
				str2 = "";
			
			ret = compareStringNum(str1, str2);
			if (ret != 0)
				return ret;

		}

		return 0;
	}



	int compareStringNum(string num1, string num2)
	{
		int i = 0;
		while (i < num1.size() && num1[i] == '0')
			i++;
		num1.erase(0, i);
		i = 0;
		while (i < num2.size() && num2[i] == '0')
			i++;
		num2.erase(0, i);
		i = num1.size() - 1;
		int j = num2.size() - 1;

		int ret = 0;

		while (i >= 0 && j >= 0)
		{
			if (num1[i] == num2[j])
			{
				if (ret == 0)
					ret = 0;
			}
			else
				ret = num1[i] > num2[j] ? 1 : -1;

			i--;
			j--;
		}

		if (i >= 0)
			ret = 1;
		else if (j >= 0)
			ret = -1;

		return ret;

	}

};
int _tmain(int argc, _TCHAR* argv[])
{
	Solution so;
	so.compareVersion("11", "10");
	return 0;
}

//solution: at the beginning, I was thinking, grab the number string from the version, compare one string by one string, see which string is bigger, and how to compare the
//number string, (I remember one problem is ask for implementing the atoi), but how about a super long string > 10 digits, overflow!!!
//so I decide to do compare character from end to beginning , one by one, which is compareStringNum did.
//I spent a lot of time on debugging the "strsub" part, just just just just just be careful plz

//PS: remove the 0s at the beginning!, they means nothing and you don't have to compare how many 0s :D
//