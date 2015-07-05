#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

/**
* Definition for singly-linked list with a random pointer.
*/
struct RandomListNode {
int label;
RandomListNode *next, *random;
RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head)
    {
        if (head == NULL)
            return NULL;
        unordered_map<RandomListNode*, int> oldlist_node2index;
        RandomListNode *cur = head;
        int count = 0;
        while (cur)
        {
            oldlist_node2index[cur] = count;
            count++;
            cur = cur->next;
        }

        int size = count;
        vector<RandomListNode*> newlist_index2node(size);
        RandomListNode *newhead = new RandomListNode(head->label);
        newlist_index2node[0] = newhead;
        RandomListNode *new_cur = newhead, *old_cur = head;
        count = 1;
        while (old_cur->next)
        {
            RandomListNode *node = new RandomListNode(old_cur->next->label);
            new_cur->next = node;
            newlist_index2node[count] = node;
            count++;

            old_cur = old_cur->next;
            new_cur = new_cur->next;
        }

        new_cur = newhead;
        old_cur = head;
        while (new_cur)
        {
            if (old_cur->random != NULL)
            {
                new_cur->random = newlist_index2node[oldlist_node2index[old_cur->random]];
            }
            new_cur = new_cur->next;
            old_cur = old_cur->next;
        }
        return newhead;
    }
};

void printRandomList(RandomListNode *head)
{
    RandomListNode *cur = head;
    while (cur)
    {
        if (cur->random)
            cout << "{ " << cur->label << ", " << cur->random->label << " }" <<  endl;
        else
            cout << "{ " << cur->label << ", " << "#" << " }" << endl;
        cur = cur->next;
    }
}

int main()
{
    Solution s;
    RandomListNode *head = new RandomListNode(1);
    cout << "src: " << endl;
    printRandomList(head);
    cout << "dst: " << endl;
    printRandomList(s.copyRandomList(head));
    system("pause");
    return 0;
}