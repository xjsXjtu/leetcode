#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	/* solution1: without using extra memory */
    ListNode *detectCycle(ListNode *head) {
		if(head==NULL || head->next==NULL) return NULL;
		ListNode *pslow = head->next, *pfast = head->next->next;
		while(pfast && pfast->next && pfast != pslow)
		{
			pfast = pfast->next->next;
			pslow = pslow->next;
		}
		if(pfast==NULL || pfast->next==NULL) return NULL;
		pfast = head;
		while(pfast != pslow)
		{
			pfast = pfast->next;
			pslow = pslow->next;
		}
		return pfast;
    }

	/* solution 2: 
	*  First, detect whether cycle exist or not
	*  Second, From head to traverse List, and insert the pointer to a map.
	*/
};