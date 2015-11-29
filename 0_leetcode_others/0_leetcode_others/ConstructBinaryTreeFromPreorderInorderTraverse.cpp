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
    typedef vector<int>::iterator vit;
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return rec(preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
    }
    
private:
    TreeNode* rec(vit prebegin, vit preend, vit inbegin, vit inend)
    {
        TreeNode *out = NULL;
        if(prebegin == preend) return out;
        out = new TreeNode(*prebegin);
        vit split = std::find(inbegin, inend, *prebegin);
        int left_size = split - inbegin;
        int right_size = inend - split;
        out->left  = rec(prebegin+1,           prebegin+1+left_size, inbegin, split);
        out->right = rec(prebegin+1+left_size, preend,               split+1, inend);
        return out;
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