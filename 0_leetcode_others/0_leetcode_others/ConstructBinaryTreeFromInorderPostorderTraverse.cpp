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
    TreeNode* buildTree(vector<int> &inorder, vector<int> &postorder) {
        return rec(inorder.begin(), inorder.end(), postorder.begin(), postorder.end());
    }
private:
    TreeNode* rec(viit_t inl, viit_t inr, viit_t postl, viit_t postr)
    {
        assert(distance(postl, postr) == distance(inl, inr));
        TreeNode *root = NULL;
        if(distance(inl, inr)==0)
        {
            return root;
        }
        root = new TreeNode(*(postr - 1));
        viit_t it = find(inl, inr, *(postr - 1));
        int left_size = distance(inl, it);
        root->left  = rec(inl, it, postl, postl + left_size);
        root->right = rec(it + 1, inr, postl + left_size, postr - 1);
        return root;
    }
    
};

TreeNode* test(int *in, int *post, int size)
{
    vector<int> postv(post, size + post), inv(in, size + in);
    Solution s;
    TreeNode* out;
    out = s.buildTree(inv, postv);
    return out;
}
int main()
{
    int post1[] = {1};
    int in1 [] = {1};
    TreeNode *out;
    out = test(in1, post1, 1);

    int post2[] = {1, 2};
    int in2 [] = {2, 1};
    out = test(in2, post2, 2);

    int post3[] = {3, 2, 4, 1};
    int in3 [] = {2, 3, 1, 4};
    out = test(in3, post3, 4);

    int in4[]   = {2,3,1};
    int post4[] = {3,2,1};
    out = test(in4, post4, 3);

    return 0;
}