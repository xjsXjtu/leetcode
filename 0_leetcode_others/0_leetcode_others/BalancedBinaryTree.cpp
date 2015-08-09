/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    int treeDepth(TreeNode* t)
    {
        if(t == NULL)
            return 0;
        return 1 + max<int>(treeDepth(t->left), treeDepth(t->right));
    }
    
    int isBalanced2Rec(TreeNode *t)
    {
        if(t == NULL)
            return 0;
        int l = isBalanced2Rec(t->left);
        int r = isBalanced2Rec(t->right);
        if(l == -1 || r == -1 || abs(l - r) > 1)
            return -1;
        else
            return max<int>(l, r) + 1;
    }
public:
    bool isBalanced(TreeNode* root)
    {
        return isBalanced_2(root);
    }
    // my stupid method: 16 ms
    bool isBalanced_1(TreeNode* root) {
        if(root == NULL)
            return true;
        int maxl = 0, maxr = 0;
        maxl = treeDepth(root->left);
        maxr = treeDepth(root->right);
        return abs(maxl - maxr) <= 1
            && isBalanced(root->left)
            && isBalanced(root->right);
    }
    
    // one method referenced from leetcode-github: 12 ms
    bool isBalanced_2(TreeNode* root)
    {
        return isBalanced2Rec(root) != -1;
    }
};
