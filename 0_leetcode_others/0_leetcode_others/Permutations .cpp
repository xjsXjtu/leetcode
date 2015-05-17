#include <iostream>
#include <vector>
#include <string>
#include "shared_functions.h"
using namespace std;

class Solution {
private:
    void permuteCore(vector<int>& nums, int start, vector<int>& path, vector<vector<int>>& out)
    {
        if(start == nums.size())
        {
            out.push_back(path);
            return;
        }
        for(int i=start; i<nums.size(); i++)
        {
            path.push_back(nums[i]);
            swap(nums[start], nums[i]);
            permuteCore(nums, start + 1, path, out);
            path.pop_back();
            swap(nums[start], nums[i]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<vector<int>> out;
        vector<int> path;
        permuteCore(nums, 0, path, out);
        return out;
    }
};

int main()
{
    int a[] = {1, 2 ,3};
    Solution s;
    printVV(s.permute(vectorConstruct(a, sizeof(a)/sizeof(int))));

    system("pause");
    return 0;
}

