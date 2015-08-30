// No19.cpp : Defines the entry point for the console application.
//


/*
Given a linked list, remove the nth node from the end of list and return its head.

For example,

Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
Given n will always be valid.
Try to do this in one pass.
*/
#include "stdafx.h"
#include <iostream>


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode* nd = head;
		int count = 1;
		while (nd->next != NULL)
		{
			count++;
			nd = nd->next;
		}

		if (count == n)
			return head->next;

		nd = head;
		int i = 0;
		while (i < count - n - 1)
		{
			nd = nd->next;
			i++;
		}

		if (nd->next != NULL)
			nd ->next = nd->next->next;

		return head;
	}
};


int _tmain(int argc, _TCHAR* argv[])
{
	//Solution so;
	//cout << so.removeNthFromEnd(? ? ? );
	return 0;
}

//this one is very fun! because I didn't use any test cases HAHAHA
//I have to admit , I summit to leetcode to see what's going on :D
//solution : first of all, find how many link nodes, 2nd, move the head to the node before the target node, 3rd link the next to next's next (skip next)

//Mistake: when count == n, means skip the head, you can't find node before head, so after figure out count, check == n
//Mistake: when I try to move to hte node before target node, i < count - n - 1 , because nd starts at head, move x times will move to x+1 node, so in order to stop at the node before
//target node, we have to make sure we only move count - n - 1 times, and i starts with 0, don't use <= !
//this problem has so many pitfalls hahahahah