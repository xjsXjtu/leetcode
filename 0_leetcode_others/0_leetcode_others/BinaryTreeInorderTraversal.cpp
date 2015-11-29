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

/** 
Definition for a binary tree node.*/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> out;
        if(root == NULL) return out;
        stack<pair<TreeNode*, int>> s;
        s.push(make_pair(root, 0));
        while(!s.empty())
        {
            auto pn = s.top();
            if(pn.first->left && pn.second==0) 
            {
                s.top().second = 1;
                s.push(make_pair(pn.first->left, 0));
            }
            else
            {
                out.push_back(pn.first->val);
                s.pop();
                if(pn.first->right) 
                {
                    s.push(make_pair(pn.first->right, 0));
                }
            }
        }
        return out;
    }
};

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    Solution s;
    auto o =  s.inorderTraversal(root);
    return 0;
}