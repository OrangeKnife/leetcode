// No83.cpp : Defines the entry point for the console application.
//
/*
Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.
*/
#include "stdafx.h"
#include <list>
#include <iostream>

using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		if (head == NULL)
			return head;
		ListNode* startNode = head;
		ListNode* lastNode = head;
		head = head->next;
		
		while (head != NULL)
		{
			if (lastNode->val == head->val)
			{
				//skip this node
				lastNode->next = head->next;
				ListNode* temp = head;
				head = head->next;
				delete temp;
			}
			else
			{
				lastNode = head;
				head = head->next;
			}

			
			
		}

		return startNode;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

//Solution is straight forward. So just check from 2nd node, see if == lastNode value, skip it if it is.

//Mistake: I forget to take care of those skipped node!!!, just delete them :(