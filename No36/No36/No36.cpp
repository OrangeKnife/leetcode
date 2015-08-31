// No36.cpp : Defines the entry point for the console application.
//

/*
Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.

A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.
*/
#include "stdafx.h"
#include <vector>;
#include <iostream>

using namespace std;
class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		bool ret = true;
		short block[9] = { 0 }, row[9] = { 0 }, column[9] = { 0 };
		for (int i = 0; i < 9; ++i)
			for (int j = 0; j < 9; ++j)
			{
				if (board[i][j] == '.') 
					continue;

				int num = board[i][j] - '0';
				short bitshift = 1 << num;
				if (block[i / 3 * 3 + j / 3] & bitshift || row[i] & bitshift || column[j] & bitshift)
					return false;

				block[i / 3 * 3 + j / 3] |= bitshift;
				row[i] |= bitshift;
				column[j] |= bitshift;

			}

		return true;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	vector<vector<char>> board(9);
	vector<string> pre_board = { ".........", "4........", "......6..", "...38....", ".5...6..1", "8......6.", ".........", "..7.9....", "...6....." };
	for (int i = 0; i < pre_board.size(); ++i)
	{
		string s = pre_board[i];
		for (auto c : s)
		{
			board[i].push_back(c);
		}
	}
	
	Solution so;
	cout << (so.isValidSudoku(board) ? "True" : "False");
	return 0;
}

//solution: This is not my original solution! mine is using another function to check vector<char> and build vectors for rows, columns, blocks,
//which is soooooooooooooooooooooooooo complicated
//the bit shift solution is very good:
//bit shifting, so a lot of times we need to check whether or not something is unique, like this case , numbers, using a short (16 bits) is good enough
//for 0-9 check.
//so one short value means a row, a column or a block
//every char inside the board will do a bit left shifting and |= to the short value, to mark it exists
//and the same time check the short & bitshift to determine whether or not it exists, return false when it exists, if iterated all the chars in the board, return true
//very simple and awesome solution
//so, combining checking rows, checking columns and checking blocks together is the key, if you check separately like me, too much work
//and using bits to record the digits, very convinent!!
