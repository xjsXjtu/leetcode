/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL) return NULL;
        if(headA == headB) return headA;
        
        ListNode *pendA = headA;
        while(pendA->next) pendA = pendA->next;
        pendA->next = headA;
        
        ListNode *pfast = headB, *pslow = headB;
        while(pfast && pfast->next)
        {
            pfast = pfast->next->next;
            pslow = pslow->next;
            if(pfast == pslow) break;
        }
        if(!pfast || !pfast->next)
        {
            pendA->next = NULL;
            return NULL;
        }
        
        ListNode *p_in_circle = pfast, *p_out_circle = headB;
        while(p_in_circle != p_out_circle)
        {
            p_in_circle = p_in_circle->next;
            p_out_circle = p_out_circle->next;
        }
        pendA->next = NULL;
        return p_in_circle;
    }
};