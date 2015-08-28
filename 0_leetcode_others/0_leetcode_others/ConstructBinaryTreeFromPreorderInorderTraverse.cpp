#include <iostream>
#include <vector>
#include <string>
#include <cassert>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
class Solution {
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

TreeNode* test(int *pre, int *in, int size)
{
    vector<int> prev(pre, size + pre), inv(in, size + in);
    Solution s;
    TreeNode* out;
    out = s.buildTree(prev, inv);
    return out;
}
int main()
{
    int pre1[] = {1};
    int in1 [] = {1};
    TreeNode *out;
    out = test(pre1, in1, 1);

    int pre2[] = {1, 2};
    int in2 [] = {2, 1};
    out = test(pre2, in2, 2);

    int pre3[] = {1, 2, 3, 4};
    int in3 [] = {2, 3, 1, 4};
    out = test(pre3, in3, 4);

    return 0;
}