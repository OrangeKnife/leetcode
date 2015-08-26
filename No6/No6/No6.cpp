// No6.cpp : Defines the entry point for the console application.
//


/*

The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".

*/
#include "stdafx.h"
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
	string convert(string s, int numRows) {

		if (numRows == 1 || numRows >= s.length())
			return s;

		string ret("");

		int sizeB = 2 * numRows - 2;
		int numB = s.length() / sizeB + 1;

		
		for (int j = 0; j < numRows; ++j)
		{

			for (int i = 0; i < numB; ++i)
			{
				size_t idx = i * sizeB + j;

				if (idx > s.length() - 1)
					continue;

				ret += s[idx];

				if (j > 0 && j < numRows -1)
				{
					size_t idx = i * sizeB + numRows + (numRows - 2 - j);

					if (idx > s.length() - 1)
						continue;

					ret += s[idx];
				}
			}
		}
		

		return ret;
	}
};



int _tmain(int argc, _TCHAR* argv[])
{
	Solution so;
	std::cout << so.convert(string("PAYPALISHIRING"),22);
	return 0;
}

//solution : I draw the garph and try to figure out the mapping of every char from "column-major" to "row-major" , I break the chars into 'blocks'
//which have one 'full char column' and (numRows - 2) 'one char column'.
//first of all is 1st row and last row, they always only have one char so just added them into the string
//then middle part of the rows: row(1) -> row(numRows - 2), every row has two chars (full char column and zigzag one char column), so take care of these rows, added them to string
//PS 1: make sure don't add out of length chars into the string
//PS 2: take care of numRows special cases: == 1 and >= s.length

//mistake: I use two loops but at the beginning, I put the j loop inside i loop, which is wrong !!!!!!! haha, you want to iterate the rows so put i into j loop.