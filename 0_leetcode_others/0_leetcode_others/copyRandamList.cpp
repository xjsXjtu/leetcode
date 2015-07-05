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

/*
*
*  The idea as below:
*
*  Consider we have a linked list as below:
*
*    node1->random = node2;
*    node2->random = node1;
*    node3->random = node1;
*
*       +-------------+
*       |             v
*    +-------+    +-------+    +-------+
*    | node1 |----> node2 |----> node3 |--->NULL
*    +-------+    +-------+    +-------+
*      ^  ^           |           |
*      |  +-----------+           |
*      +--------------------------+
*
*
*  To copy the list,
*
*    1) We insert a new node for each node's next position
*
*
*       +-------------------------+
*       |                         v
*    +--+----+     +-----+    +-------+     +-----+    +-------+     +-----+
*    | node1 |---> | NEW |----> node2 |---> | NEW |----> node3 |---> | NEW | ---> NULL
*    +-------+     +-----+    +---+---+     +-----+    +--+----+     +-----+
*      ^  ^                       |                       |
*      |  +-----------------------+                       |
*      +--------------------------------------------------+
*
*    2) Then, we can construt the new node's random pointer:
*
*        (node1->next) -> random  = (node1->random) -> next;
*
*    3) After we take out all of the "NEW" node to finish the copy.
*
*/

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        RandomListNode *p = NULL, *h = NULL, *t = NULL;
        if (head == NULL){
            return NULL;
        }

        //creat a new node for each node and insert its next
        p = head;
        while (p != NULL){
            RandomListNode *node = new RandomListNode(p->label);
            node->next = p->next;
            p->next = node;
            p = node->next;
        }

        //copy random pointer for each new node
        p = head;
        while (p != NULL){
            if (p->random != NULL){
                p->next->random = p->random->next;
            }
            p = p->next->next;
        }

        //break to two list
        p = head;
        h = t = head->next;
        while (p != NULL){
            p->next = p->next->next;
            if (t->next != NULL){
                t->next = t->next->next;
            }

            p = p->next;
            t = t->next;
        }

        return h;
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