// No23.cpp : Defines the entry point for the console application.
//


//Merge k Sorted Lists
/*
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
*/
#include "stdafx.h"
#include <vector>
using namespace std;
//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
class Solution {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {

		int len = lists.size();
		if (len == 0)
			return NULL;

		while (len > 1)
		{
			for (int i = 0; i < (len) / 2; ++i)
				lists[i] = merge2Lists(lists[i], lists[len - 1 - i]);

			len = (len + 1) / 2;
		}

		return lists[0];
	}

	ListNode* merge2Lists(ListNode* list1, ListNode* list2)
	{
		ListNode* head1 = list1;
		ListNode* head2 = list2;
		ListNode* pre1 = NULL;
		ListNode* ret = list1;

		if (!list1)
			return list2;
		else if (!list2)
			return list1;


		while (head1 && head2)
		{
			if (head1->val < head2->val)
			{
				pre1 = head1;
				head1 = head1->next;
			}
			else
			{
				if (pre1)
				{
					pre1->next = head2;
				}
				else
				{
					ret = head2;
				}

				ListNode* temp2 = head2->next;
				head2->next = head1;
				pre1 = head2;
				head2 = temp2;

			}
		}

		if (head2)
			pre1->next = head2;

		return ret;
	}
};

//so , use the function merge2lists to merge k lists
//0 - size()-1
//1 - size()-2 
//to narrow down the whole length
//then do it agian until get len == 1
//return lists[0]

//PS, make sure you get the correct idx of the list from lists
//PS2, make sure merge2Lists has edge cases covered (NULL pointers)
//klogk * n

int _tmain(int argc, _TCHAR* argv[])
{
	vector<ListNode*> test = { new ListNode(0), new ListNode(1) };
	Solution so;
	so.mergeKLists(test);
	return 0;
}

