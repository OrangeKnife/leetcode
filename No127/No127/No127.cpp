// No127.cpp : Defines the entry point for the console application.
//
/*
Word Ladder

Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the word list
For example,

Given:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]
As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.

Note:
Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.

*/
#include "stdafx.h"
#include <string>
#include <unordered_set>
using namespace std;
class Solution {
public:
	struct stringNode
	{
		string s;
		int depth;
		stringNode(string _s, int d) :s(_s), depth(d)
		{}
	};

	int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
		if (wordList.count(endWord) == 0)
			wordList.insert(endWord);
		if (wordList.count(beginWord) > 0)
			wordList.erase(beginWord);
		unordered_set<string> checked;
		checked.insert(beginWord);

		int depth = 1;
		while (checked.count(endWord) == 0)
		{
			unordered_set<string> toAdd;
			for (auto it = checked.begin(); it != checked.end(); ++it)
			{
				string aword = *it;
				for (int i = 0; i < aword.size(); ++i)
				{
					for (char c = aword[i], j = 'a'; j <= 'z'; ++j)
					{
						if (j == c)
							continue;

						string newStr = aword;
						newStr[i] = j;
						if (wordList.count(newStr) > 0)
						{
							toAdd.insert(newStr);
							wordList.erase(newStr);
						}

					}
				}
			}


			if (toAdd.size() == 0)
				return 0;
			checked = toAdd;
			depth++;
		}

		return depth;
	}
};


//solution, BFS, track the depth
//so you have a wordlist containing all the possible strings,
//from beginWord, generate strings that inside wordlist and add to checked set, whenever you find endword is insde checked set
//stop searching
//output the depth


int _tmain(int argc, _TCHAR* argv[])
{
	Solution so;
	unordered_set<string> wordlist = {"a","b","c"};
	so.ladderLength(string("a"), string("c"), wordlist);
	return 0;
}

