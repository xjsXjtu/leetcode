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
    ListNode* sortList(ListNode* head) 
    {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode *n1=head, *n2=head;
        while(n2->next && n2->next->next)
        {
            n1 = n1->next;
            n2 = n2->next->next;
        }
        n2 = n1->next;
        n1->next = NULL;
        n1 = sortList(head);
        n2 = sortList(n2);
        return mergeSortedLists(n1, n2);
    }
private:
    ListNode* mergeSortedLists(ListNode* head1, ListNode* head2)
    {
        if(head1 == NULL || head2 == NULL)
            return head1 == NULL ? head2 : head1;
        ListNode dummy(0), *tail = &dummy;
        while(head1 && head2)
        {
            if(head1->val < head2->val)
            {
                tail->next = head1;
                head1 = head1->next;
            }
            else
            {
                tail->next = head2;
                head2 = head2->next;
            }
            tail = tail->next;
            tail->next = NULL;
        }
        tail->next = head1==NULL ? head2 : head1;
        return dummy.next;
    }
};

int main()
{
    ListNode head(3), *tail = &head, n1(2), n2(4);
    Solution s;
    ListNode *out;

    tail = &head;
    tail->next =  NULL;
    out = s.sortList(&head);
    
    tail = &head;
    tail->next = &n1; tail = tail->next; tail->next = NULL;
    out = s.sortList(&head);

    tail = &head;
    tail->next = &n1; tail = tail->next; tail->next = NULL;
    tail->next = &n2; tail = tail->next; tail->next = NULL;
    out = s.sortList(&head);

    return 0;
}