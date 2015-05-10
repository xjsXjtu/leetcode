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
		ListNode *out=NULL, *cur=NULL;
		while(l1 && l2)
		{
			if(l1->val < l2->val)
			{
				if(cur != NULL)
					cur->next = l1;
				cur = l1;
				l1 = l1->next;
			}
			else 
			{
				if(cur != NULL)
					cur->next = l2;
				cur = l2;
				l2 = l2->next;
			}	
			if(out == NULL)
				out = cur;
		}
		while(l1)
		{
			if(cur != NULL)
				cur->next = l1;
			cur = l1;
			l1 = l1->next;
			if(out == NULL)
				out = cur;
		}
		while(l2)
		{
			if(cur != NULL)
				cur->next = l2;
			cur = l2;
			l2 = l2->next;
			if(out == NULL)
				out = cur;
		}
		return out;
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
	
	//test(head1, head2);
	test(head1, NULL);
	system("pause");
	return 0;
}