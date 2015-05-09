/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) 
	{
		if(n<1)
			return NULL;

		ListNode newhead(-1);
		ListNode *pnewhead = &newhead;
		pnewhead->next = head;

		ListNode *right = head;
		int count = 1;
		while(right != NULL && count < n)
		{
			right = right->next;
			count++;
		}
		if(count < n)
			return NULL;

		ListNode *left = pnewhead;
		while(right->next != NULL)
		{
			left = left->next;
			right = right->next;
		}
		left->next = left->next->next;
		return newhead.next;
    }
};

void test(ListNode *head, int n)
{
	Solution s;
	head = s.removeNthFromEnd(head, n);
	while(head != NULL)
	{
		cout << head->val << endl;;
		head = head->next;
	}

}
int main()
{
	// [1, 2], 1 ==> [1]
#if 1
	ListNode *head = &ListNode(1);
	ListNode *tail = head;
	tail->next = &ListNode(2);
	test(head, 1);
#endif

#if 0
	// [1], 1 ==> []
	ListNode *head = &ListNode(1);
	ListNode *tail = head;
	test(head, 1);

#endif
	system("pause");
	return 0;
}
