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
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if(root == NULL)
            return res;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        vector<int> level;
        while(1)
        {
            TreeNode *t = q.front(); q.pop();
            if(t == NULL)
            {
                res.push_back(level);
                level.clear();
                if(q.empty())
                {
                    reverse(res.begin(), res.end());
                    return res;
                }
                q.push(NULL);
            }
            else
            {
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
                level.push_back(t->val);
            }
        }
    }
};