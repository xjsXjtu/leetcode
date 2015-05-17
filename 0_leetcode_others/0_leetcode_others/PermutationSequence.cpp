#include <iostream>
#include <vector>
#include <string>
#include "shared_functions.h"
using namespace std;

class Solution {
private:
    bool permuteCore(vector<int>& nums, int start, string& path, int &seq, int k)
    {
        if(start == nums.size())
        {
            // cout << path << endl;
            seq++;
            if(seq == k)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        for(int i=start; i<nums.size(); i++)
        {
            path.push_back(nums[i]);
            swap(nums[start], nums[i]);
            if(permuteCore(nums, start + 1, path, seq, k))
                return true;
            path.pop_back();
            swap(nums[start], nums[i]);
        }
        return false;
    }
public:
    string getPermutation(int n, int k)
    {
        string path;
        vector<int> nums;
        int seq = 0;
        for(int i=1; i<n+1; i++)
            nums.push_back(i + '0');
        permuteCore(nums, 0, path, seq, k);
        return path;
    }
};

int main()
{
    Solution s;
    cout << endl << s.getPermutation(3, 3) << endl;

    system("pause");
    return 0;
}

