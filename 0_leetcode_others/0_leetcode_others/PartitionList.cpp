#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode dummy1(0), *tail1 = &dummy1, dummy2(3), *tail2 = &dummy2;
        ListNode *cur = head;
        while(cur)
        {
            if(cur->val < x)
            {
                tail1->next = cur;
                tail1 = tail1->next;
            }
            else
            {
                tail2->next = cur;
                tail2 = tail2->next;
            }
            cur = cur->next;
        }
		tail2->next = NULL;
        tail1->next = dummy2.next;
        return dummy1.next;
    }
};

ListNode* test(int *a, int size, int x)
{
	ListNode dummy(0), *tail = &dummy;
	for(int i=0; i<size; i++)
	{
		ListNode *newn = new ListNode(a[i]);
		tail->next = newn;
		tail = tail->next;
	}
	Solution s;
	return s.partition(dummy.next, x);
}

int main()
{
	int a[] = {1};
	ListNode *out = NULL;
	out = test(a, 0, 0);
	out = test(a, 1, 0);
	out = test(a, 1, 2);

	int a2[] = {2, 1};
	out = test(a2, 2, 2);

	int a3[] = {1, 4, 3, 2, 5, 2 };
	out = test(a3, sizeof(a3)/sizeof(int), 3);

	return 0;
}