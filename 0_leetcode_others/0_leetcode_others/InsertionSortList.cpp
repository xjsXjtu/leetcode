#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode pivot(0);
        pivot.next = head;
        ListNode *p_curr = head->next, *p_next = NULL;

        head->next = NULL;
        while(p_curr)
        {
            p_next = p_curr->next;
            
            ListNode *p_insert = &pivot;
            while(p_insert->next && p_curr->val >= p_insert->next->val)
                p_insert = p_insert->next;

            p_curr->next = p_insert->next;
            p_insert->next = p_curr;
            
            p_curr = p_next;
        }
        return pivot.next;
    }
};

int main()
{
    ListNode head(3), *tail = &head, n1(2), n2(4);
    tail->next = &n1; tail = tail->next;
    tail->next = &n2; tail = tail->next;
    tail->next = NULL;
    
    Solution s;
    tail = s.insertionSortList(&head);
    return 0;

}