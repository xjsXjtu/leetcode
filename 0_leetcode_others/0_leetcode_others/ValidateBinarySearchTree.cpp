 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

 class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(root==NULL )
            return true;
        bool out = true;
        if(root->left) 
        {
            out = out && isValidBST(root->left) && root->val > bstGetMax(root->left);
        }
        if(root->right) 
        {
            out = out && isValidBST(root->right) && root->val < bstGetMin(root->right);
        }
        return out;
    }
private:
    int bstGetMin(TreeNode *root)
    {
        assert(root);
        while(root->left)
            root = root->left;
        return root->val;
    }
    int bstGetMax(TreeNode *root)
    {
        assert(root);
        while(root->right)
            root = root->right;
        return root->val;
    }

};