#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        return rec(1, n);
    }
private:
    vector<TreeNode*> rec(int left, int right)
    {
        vector<TreeNode*> out;
        if(left > right)
        {
            out.push_back(NULL);
            return out;
        }
        if(left == right)
        {
            TreeNode *tmp = new TreeNode(left);
            out.push_back(tmp);
            return out;
        }
        for(int i=left; i<=right; i++)
        {
            vector<TreeNode*> left_trees = rec(left, i-1);
            vector<TreeNode*> right_trees = rec(i+1, right);
            int left_size = left_trees.size();
            int right_size = right_trees.size();
            for(int ileft=0; ileft<left_size; ileft++)
            {
                for(int iright=0; iright<right_size; iright++)
                {
                    TreeNode *temp = new TreeNode(i);
                    temp->left = left_trees[ileft];
                    temp->right = right_trees[iright];
                    out.push_back(temp);
                }
            }
        }
        return out;
    }
};

int main()
{
    Solution s;
    vector<TreeNode*> out;
    out = s.generateTrees(0);
    out = s.generateTrees(1);
    out = s.generateTrees(3);
    out = s.generateTrees(4);

    system("pause");
    return 0;
}