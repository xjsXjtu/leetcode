#include <cassert>
#include <cstdint>

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
// #include <initializer_list>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL) return head;
        ListNode dummy(0);
        dummy.next = head;

        ListNode *pslow = &dummy, *pfast = dummy.next;
        while(pfast)
        {
            while(pfast->next && pfast->val == pfast->next->val)
                pfast = pfast->next;
            if(pslow->next != pfast)
            {
                pslow->next = pfast->next;
                pfast = pfast->next;
            }
            else
            {
                pslow = pfast;
                pfast = pfast->next;
            }
        }
        return dummy.next;
    }
};

ListNode* test(int *a, int size)
{
    ListNode dummy(0), *p = &dummy;
    for(int i=0; i<size; i++)
    {
        p->next = new ListNode(a[i]);
        p = p->next;
    }
    Solution s;
    return s.deleteDuplicates(dummy.next);
}

int main()
{
    ListNode* out = NULL;
    
    int a2[] = {1};
    out = test(a2, 0);
    out = test(a2, sizeof(a2)/sizeof(int));

    int a3[] = {1, 2};
    out = test(a3, sizeof(a3)/sizeof(int));

    int a31[] = {1, 1};
    out = test(a31, sizeof(a31)/sizeof(int));

    int a4[] = {1, 1, 2};
    out = test(a4, sizeof(a4)/sizeof(int));

    int a5[] = {1, 2, 2};
    out = test(a5, sizeof(a5)/sizeof(int));

    int a6[] = {1, 1, 1, 2, 2, 2};
    out = test(a6, sizeof(a6)/sizeof(int));
}
