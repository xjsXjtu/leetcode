#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>
#include "shared_functions.h"
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == NULL)
            return NULL;
        ListNode *end = head;
        while(end->next) end = end->next;
        return rec(head, end);
    }
private:
    TreeNode* rec(ListNode* head, ListNode* end)
    {
        if(head == NULL)
            return NULL;
        TreeNode *out;
        if(head == end)
        {
            return out = new TreeNode(head->val);
        }
        // head, mid, end
        ListNode *midprev = head, *midprev2 = head->next;
        while(midprev2 != end && midprev2->next != end)
        {
            midprev2 = midprev2->next->next;
            midprev = midprev->next;
        }
        ListNode *mid = midprev->next;
        out = new TreeNode(mid->val);
        out->left = rec(head, midprev);
        if(mid != end)
            out->right = rec(mid->next, end);
        return out;
    }
};

TreeNode* test(int *arr, int size)
{
    assert(size>0);
    ListNode* head = new ListNode(arr[0]), *end = head;
    Solution s;
    TreeNode *out = NULL;

    for(int i=1; i<size; i++)
    {
        end->next = new ListNode(arr[i]);
        end = end->next;
    }
    out = s.sortedListToBST(head);
    return out;
}
TreeNode* testEmpty()
{
    vector<int> nums;
    Solution s;
    TreeNode *out = NULL;

    out = s.sortedListToBST(NULL);
    return out;
}


int main()
{
    TreeNode *out;
    out = testEmpty();
    
    int a[] = {0};
    out = test(a, sizeof(a)/sizeof(int));

    int b[] = {0, 1};
    out = test(b, sizeof(b)/sizeof(int));

    int c[] = {0, 1, 2};
    out = test(c, sizeof(c)/sizeof(int));

    int d[] = {0, 1, 2, 3};
    out = test(d, sizeof(d)/sizeof(int));

}