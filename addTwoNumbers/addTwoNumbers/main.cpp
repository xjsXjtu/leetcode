#include <iostream>
#include <vector>

//  Definition for singly-linked list.
struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *out = NULL;
        ListNode *tail = out;
        
        if(!l1 || !l2)
        {
            return NULL;
        }

        int s = l1->val + l2->val;
        int carry = s / 10;
        ListNode *temp = new ListNode(s % 10);
        out = temp;
        tail = out;
        l1 = l1->next;
        l2 = l2->next;
        while(l1 && l2)
        {
            int s = carry + l1->val + l2->val;
            carry = s / 10;
            s = s % 10;
            l1 = l1->next;
            l2 = l2->next;

            ListNode *temp = new ListNode(s);
            tail->next = temp;
            tail = tail->next;
        }

        if(l2)
        {
            l1 = l2;
        }

        while(l1)
        {
            int s = l1->val + carry;
            carry = s / 10;
            s = s % 10;
            l1 = l1->next;

            ListNode *temp = new ListNode(s);
            tail->next = temp;
            tail = tail->next;
        }

        if(carry)
        {
            ListNode *temp = new ListNode(carry);
            tail->next = temp;
            tail = tail->next;
        }

        return out;
    }
};

int main()
{
    ListNode *t = NULL, *lt1 = NULL, *lt2 = NULL, *tail = NULL;
    t = new ListNode(2); lt1  = t; tail = lt1;
    t = new ListNode(4); tail->next = t; tail = tail->next;
    t = new ListNode(3); tail->next = t; tail = tail->next;
    t = new ListNode(5); lt2  = t; tail = lt2;
    t = new ListNode(6); tail->next = t; tail = tail->next;
    t = new ListNode(4); tail->next = t; tail = tail->next;

    Solution s;
    ListNode *out = s.addTwoNumbers(lt1, lt2);
    while(out)
    {
        printf("%d -> ", out->val);
        out = out->next;
    }

    system("pause");
}