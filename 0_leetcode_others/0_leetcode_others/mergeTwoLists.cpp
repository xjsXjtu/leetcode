#include <iostream>
using namespace std;

#if 1
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
#endif

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
	{
		ListNode dummy(0);
		ListNode *cur = &dummy;
		while(l1 && l2)
		{
			if(l1->val < l2->val)
			{
				cur->next = l1;
				l1 = l1->next;
			}
			else 
			{
				cur->next = l2;
				l2 = l2->next;
			}	
			cur = cur->next;
		}
		if(l1) 
			cur->next = l1;
		if(l2)
			cur->next = l2;
		return dummy.next;
    }
};

void test(ListNode *head1, ListNode *head2)
{
	Solution s;
	ListNode *head = s.mergeTwoLists(head1, head2);
	while(head != NULL)
	{
		cout << head->val << endl;;
		head = head->next;
	}
}

int main()
{
	ListNode *head1 = &ListNode(1);
	ListNode *tail = head1;
	tail->next = &ListNode(3);

	ListNode *head2 = &ListNode(2);
	tail = head2;
	tail->next = &ListNode(3);
	
	test(head1, head2);
	//test(head1, NULL);
	system("pause");
	return 0;
}