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
public:
    bool isValidBST_2(TreeNode* root) {
        int max, min;
        return rec(root, &max, &min);
    }
private:
    bool rec(const TreeNode* root, int *max, int *min)
    {
        if(root==NULL) return true;
        if(root->left == NULL && root->right == NULL)
        {
            *max = *min = root->val;
            return true;
        }
        int max1, min1;
        *max = *min = root->val;
        if(root->left)
        {
            if(false == rec(root->left, &max1, &min1)) return false;
            if(root->val <= max1) return false;
            *min = min1;
        }
        if(root->right)
        {
            if(false == rec(root->right, &max1, &min1)) return false;
            if(root->val >= min1) return false;
            *max = max1;
        }
        return true;
    }
};