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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL) return head;
        int len = lenOfList(head);
        k = k % len;
        if(k==0) return head;
        ListNode* pfast = head, *pslow = head;
        for(int i=0; i<k; i++)
        {
            pfast = pfast->next;
        }
        while(pfast->next)
        {
            pfast = pfast->next;
            pslow = pslow->next;
        }
        pfast->next = head;
        head = pslow->next;
        pslow->next = NULL;
        return head;
    }
private:
    int lenOfList(ListNode* head)
    {
        if(head==NULL) return 0;
        int l = 1;
        while(head->next)
        {
            l++;
            head = head->next;
        }
        return l;
    }
};

ListNode* test(int *a, int size, int k)
{
    ListNode dummy(0), *p = &dummy;
    for(int i=0; i<size; i++)
    {
        p->next = new ListNode(a[i]);
        p = p->next;
    }
    Solution s;
    return s.rotateRight(dummy.next, k);
}

int main()
{
    ListNode* out = NULL;
    
    int a2[] = {1};
    out = test(a2, 0, 0);
    out = test(a2, sizeof(a2)/sizeof(int), 1);

    int a3[] = {1, 2, 3, 4, 5};
    out = test(a3, sizeof(a3)/sizeof(int), 0);
    out = test(a3, sizeof(a3)/sizeof(int), 1);
    out = test(a3, sizeof(a3)/sizeof(int), 2);
    out = test(a3, sizeof(a3)/sizeof(int), 5);
    out = test(a3, sizeof(a3)/sizeof(int), 6);
}