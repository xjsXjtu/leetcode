#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "shared_functions.h"
using namespace std;

class Solution {
private:
    void combineRecursive(vector<int>& nums, int k, int start, vector<int>& path, vector<vector<int>>& out)
    {
        int n = nums.size();
        if(path.size() == k)
        {
            out.push_back(path);
            return;
        }
        for(int i=start; i<n-k+2+path.size(); i++)
        {
            path.push_back(nums[i-1]);
            combineRecursive(nums, k, i+1, path, out);
            path.pop_back();
        }
    }
public:
    // C(n, k) (n >= K)
    vector<vector<int>> subsets(vector<int>& nums)
    {
        vector<vector<int>> out;
        vector<int> path;
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size()+1; i++)
        {
            combineRecursive(nums, i, 1, path, out);
        }
        return out;
    }
};

int main()
{
    int a[] = {1, 2, 3};
    vector<int> nums(a, a + sizeof(a)/sizeof(int));
    Solution s;
    printVV(s.subsets(nums));
    system("pause");
    return 0;
}