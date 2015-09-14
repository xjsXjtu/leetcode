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
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* p = &dummy;
        while(p && p->next && p->next->next)
        {
            ListNode *p2 = p->next->next;
            p->next->next = p2->next;
            p2->next = p->next;
            p->next = p2;
            p = p->next->next;
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
    return s.swapPairs(dummy.next);
}

int main()
{
    ListNode* out = NULL;
    
    int a2[] = {1};
    out = test(a2, 0);
    out = test(a2, sizeof(a2)/sizeof(int));

    int a3[] = {1, 2};
    out = test(a3, sizeof(a3)/sizeof(int));
    
    int a4[] = {1, 2, 3};
    out = test(a4, sizeof(a4)/sizeof(int));

    int a5[] = {1, 2, 3, 4};
    out = test(a5, sizeof(a5)/sizeof(int));

}