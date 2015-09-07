#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>
#include "shared_functions.h"
#include "ConstructBinaryTreeFromPreorderInorderTraverse.h"
using namespace std;


class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> out;
        vector<int> path;
        if(root == NULL)
            return out;
        rec(root, sum, out, path);
        return out;
    }
private:
    void rec(TreeNode *root, int sum, vector<vector<int>>& out, vector<int>& path)
    {
        if(root->left == NULL && root->right == NULL)
        {
            if(sum == root->val)
            {
                path.push_back(root->val);
                out.push_back(path);
            }
            return;
        }
        path.push_back(root->val);
        vector<int> bak(path);
        if(root->left)
            rec(root->left, sum - root->val, out, path);
        if(root->right)
            rec(root->right, sum - root->val, out, bak);
        return;
    }
};

vector<vector<int>> test(int *inorder, int *preorder, int size, int sum)
{
    ConstructTree ct;
    vector<int> ino(inorder, inorder + size);
    vector<int> preo(preorder, preorder + size);
    TreeNode *root = ct.buildTree(preo, ino);
    Solution s;
    return s.pathSum(root, sum);
}

int main()
{
    vector<vector<int>> out;
    
    int ino[] = {1};
    int preo[] = {1};
    int sum = 1;
    out = test(ino, preo, sizeof(ino)/sizeof(int), sum);

    int ino1[] = {7, 11, 2, 4, 5, 13, 8, 5, 4, 1};
    int preo1[] = {5, 4, 11, 7, 2, 8, 13, 4, 5, 1};
    int sum1 = 22;
    out = test(ino1, preo1, sizeof(ino1)/sizeof(int), sum1);

    return 0;
}