#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "shared_functions.h"
using namespace std;

class Solution {
private:
    void permuteCore(vector<int>& nums, int k, vector<int>& path, vector<vector<int>>& out)
    {
        if(k == 0)
        {
            out.push_back(path);
            return;
        }
        for(int i=0; i<nums.size() - k + 1; i++)
        {
            path.push_back(nums[i]);
            vector<int> nums_bak(nums);
            nums.erase(nums.begin(), nums.begin() + i + 1);
            permuteCore(nums, k-1, path, out);
            nums = nums_bak;
            path.pop_back();
        }
    }
public:
    // C(n, k) (n >= K)
    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>> out;
        vector<int> path;
        vector<int> nums;
        for(int i=1; i<n+1; i++)
            nums.push_back(i);
        permuteCore(nums, k, path, out);
        return out;
    }
};

int main()
{
    int a[] = {1, 2 ,3};
    Solution s;
    printVV(s.combine(4, 2));

    system("pause");
    return 0;
}

