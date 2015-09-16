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

#include "shared_functions.h"

using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
class ConstructTree {
    typedef vector<int>::iterator viit_t;
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return rec(preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
    }
private:
    TreeNode* rec(viit_t prel, viit_t prer, viit_t inl, viit_t inr)
    {
        int n = distance(prel, prer);
        n = distance(inl, inr);
        assert(distance(prel, prer) == distance(inl, inr));
        TreeNode *root = NULL;
        if(distance(prel, prer)==0)
        {
            return root;
        }
        root = new TreeNode(*prel);
        viit_t it = find(inl, inr, *prel);
        int next_presize = distance(inl, it);
        root->left  = rec(prel + 1, prel + 1 + next_presize, inl, it);
        root->right = rec(prel + 1 + next_presize, prer, it + 1, inr);
        return root;
    }
    
};