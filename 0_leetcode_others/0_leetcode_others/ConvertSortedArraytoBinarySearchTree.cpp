#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return rec(nums, 0, nums.size() - 1);
    }
private:
    TreeNode* rec(vector<int> &nums, int start, int end)
    {
        TreeNode *out = NULL;
        if(start > end)
            return out = NULL;
        if(start == end)
            return out = new TreeNode(nums[start]);
        int mid = start + (end - start + 1) / 2;
        out = new TreeNode(nums[mid]);
        out->left  = rec(nums, start, mid - 1);
        out->right = rec(nums, mid + 1, end);
        return out;
    }
};

TreeNode* test(int *arr, int size)
{
    vector<int> nums(arr, arr + size);
    Solution s;
    TreeNode *out = NULL;

    out = s.sortedArrayToBST(nums);
    return out;
}
TreeNode* testEmpty()
{
    vector<int> nums;
    Solution s;
    TreeNode *out = NULL;

    out = s.sortedArrayToBST(nums);
    return out;
}


int main()
{
    TreeNode *out;
    out = testEmpty();
    
    int a[] = {0};
    out = test(a, sizeof(a)/sizeof(int));

    int b[] = {0, 1};
    out = test(b, sizeof(b)/sizeof(int));

    int c[] = {0, 1, 2};
    out = test(c, sizeof(c)/sizeof(int));

    int d[] = {0, 1, 2, 3};
    out = test(d, sizeof(d)/sizeof(int));

}

