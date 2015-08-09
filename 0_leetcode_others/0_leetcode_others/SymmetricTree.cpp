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
    bool isSymmetricRec(TreeNode* l, TreeNode* r)
    {
        if(l==NULL && r==NULL)
            return true;
        else if(l==NULL || r==NULL)
            return false;
        return l->val == r->val
            && isSymmetricRec(l->left, r->right)
            && isSymmetricRec(l->right, r->left);
    }
public:
    bool isSymmetric_1(TreeNode* root) {
        if(root == NULL)
            return true;
        else
            return isSymmetricRec(root->left, root->right);
    }
    
    bool isSymmetric(TreeNode* root)
    {
        if(root == NULL)
            return true;
        stack<TreeNode*> s;
        s.push(root->left);
        s.push(root->right);
        while(!s.empty())
        {
            TreeNode *tl = s.top(); s.pop();
            TreeNode *tr = s.top(); s.pop();
            if(tl==NULL && tr==NULL)
                continue;
            else if(tl==NULL || tr==NULL || tl->val != tr->val)
                return false;
            s.push(tl->left);
            s.push(tr->right);
            s.push(tl->right);
            s.push(tr->left);
        }
        return true;
    }
};
