// No20.cpp : Defines the entry point for the console application.
//

/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
*/
#include "stdafx.h"
#include <string>
#include <iostream>
#include <stack>

using namespace std;
/*
class Solution {
public:
bool isValid(string s) {
bool ret = true;
for (size_t i = 0; i < s.length(); ++i)
{
char c = s[i];
switch (c)
{
case '(':
case '{':
case '[':
ret = ret && check(s, i);
if (!ret)
return ret;
else


break;
default:
return false;
}
}

return ret;
}

bool check(string s, size_t& currentIdx)
{
bool ret = true;
char curChar = s[currentIdx];
char searchFor;


if (curChar == '(') searchFor = ')';
else if (curChar == '{') searchFor = '}';
else if (curChar == '[') searchFor = ']';
else return false;

for (size_t i = currentIdx; i < s.length(); ++i)
{
if (s[i] == searchFor)
{
ret = ret && isValid(s.substr(currentIdx+1, i - currentIdx - 1));
currentIdx = i;

return ret;
}

}

return false;
}
};
*/
class Solution {
public:
	bool isValid(string s) {
		stack<char> astack;
		bool ret = true;
		for (size_t i = 0; i < s.length(); ++i)
		{
			char c = s[i];
			char open = 0;
			switch (c)
			{
			case '(':
			case '{':
			case '[':
				astack.push(c);
				break;
			case ')': open = '(';
				ret = ret && (astack.size()>0 && astack.top() == open);
				astack.pop();
				break;
			case ']': open = '[';
				ret = ret && (astack.size()>0 && astack.top() == open);
				astack.pop();
				break;
			case '}': open = '{';
				ret = ret && (astack.size()>0 && astack.top() == open);
				astack.pop();
				break;

				
			default:
				return false;
			}

			if (!ret)
				return ret;
		}

		return ret && astack.size() == 0;
	}

};
int _tmain(int argc, _TCHAR* argv[])
{
	Solution so;
	cout << (so.isValid("({]])]})]}([)}{][)]{}{(])}([]}])})}([]}({}([{][{}") ? "True" : "False");
	return 0;
}

//solution 1 is wrong solution: no stack solution, can't recognize {(())} because the first ) I will check the inside (, doesn't meet the requirement.
//solution 2: stack solution, check stack top whenever you found a close bracket

//Mistake : when you try to read top stack, what if it's an empty stack? check the size first
//Mistake : if your found something already make ret value false, don't keep reading chars
//Mistake : what if you don't find any close brackets? check if the stack size == 0 at the end!

//I like this one, so many mistakes will make :(