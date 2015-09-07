#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include "ConstructBinaryTreeFromPreorderInorderTraverse.h"
using namespace std;

class Solution {
public:
    void flatten(TreeNode* root) {
        if(root == NULL)
            return;
        flatten(root->left);
        flatten(root->right);
        if(root->left)
        {
            TreeNode* leftend = root->left;
            while(leftend->right) leftend = leftend->right;
            leftend->right = root->right;
            root->right = root->left;
            root->left = NULL;
        }
    }
};

TreeNode *test(int *inorder, int *preorder, int size)
{
    ConstructTree ct;
    vector<int> ino(inorder, inorder + size);
    vector<int> preo(preorder, preorder + size);
    TreeNode *root = ct.buildTree(preo, ino);
    Solution s;
    s.flatten(root);
    return root;
}

int main()
{
    TreeNode *out;
    
    int ino[] = {1};
    int preo[] = {1};
    out = test(ino, preo, sizeof(ino)/sizeof(int));

    int ino2[] = {2, 1};
    int preo2[] = {1, 2};
    out = test(ino2, preo2, sizeof(ino2)/sizeof(int));

    int ino3[] = {1, 2};
    int preo3[] = {1, 2};
    out = test(ino3, preo3, sizeof(ino3)/sizeof(int));

    int ino1[] = {3, 2, 4, 1, 5, 6};
    int preo1[] = {1, 2, 3, 4, 5, 6};
    out = test(ino1, preo1, sizeof(ino1)/sizeof(int));

    return 0;
}