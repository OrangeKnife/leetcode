// No21.cpp : Defines the entry point for the console application.
//

/*
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
*/

#include "stdafx.h"

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (l1 == NULL && l2 == NULL)
			return NULL;
		
		ListNode* nd1 = l1; 
		ListNode* nd2 = l2;
		 
		ListNode* lastNode = NULL;
		ListNode* ret = l1;
		for (; nd1 && nd2; )
		{
			if (nd1->val > nd2->val)
			{
				if (lastNode != NULL)
					lastNode->next = nd2;
				else
					ret = l2;

				ListNode* newNd2 = nd2->next;
				nd2->next = nd1;

				lastNode = nd2;
				nd2 = newNd2;

			}
			else
			{
				lastNode = nd1;
				nd1 = nd1->next;
				
			}
			

			
			
		}

		if (nd2)
		{
			if (lastNode)
				lastNode->next = nd2;
			else if (l1)
				nd1->next = nd2;
			else
				ret = l2;

		}
			
		 
		return ret;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	int array1[1] = { 3};
	int array2[1] = {  7 };
	ListNode* a1 = new ListNode(-9); ListNode* head1 = a1;
	ListNode* a2 = new ListNode(5); ListNode* head2 = a2;
	for (auto i : array1)
	{
	ListNode* a = new ListNode(i);
	a1->next = a;
	a1 = a;

	}

	for (auto i : array2)
	{
		ListNode* a = new ListNode(i);
		a2->next = a;
		a2 = a;
	}

	Solution so;
	so.mergeTwoLists(head1, head2);
	return 0;
}

//solution: idea is very simple, go through both lists, two pointers, compare the values and insert list2 nodes into list1 nodes
//1) if list2 node is smaller than list1 node, insert the list2 node in front of list1 node. there is a pitfall that the bigger node is the first node, in this case, return head shall be the small node
//which is list2 head
//2)when you insert a list2 node into list1 node, need to re-order the list1 nodes, lastnode will be list2 node, and list2 node will point to lastnode->next. Pay attention to the next value
//3)if run out of list1 nodes, but still have list2 nodes left, which means those left list2 nodes are bigger than all the list1 nodes, attach them to the end. 
//Pitfall: what if lastNode == null, which means all the list1 nodes are smaller than list2 nodes, so attach to the end of list1
//Pitfall: what if list1 == null, return list2;


//Mistake : pay attention to those NULL lists, only both lists are NULL, you can return null, otherwise just return the non-null list
