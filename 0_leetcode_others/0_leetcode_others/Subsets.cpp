#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "shared_functions.h"
using namespace std;

class Solution {
private:
    void combineRecursive(int n, int k, int start, vector<int>& path, vector<vector<int>>& out)
    {
        if(path.size() == k)
        {
            out.push_back(path);
            return;
        }
        for(int i=start; i<n-k+2+path.size(); i++)
        {
            path.push_back(i);
            combineRecursive(n, k, i+1, path, out);
            path.pop_back();
        }
    }

    // C(n, k) (n >= K)
    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>> out;
        vector<int> path;
        combineRecursive(n, k, 1, path, out);
        return out;
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        vector<vector<int>> out;
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size()+1; i++)
        {
            vector<vector<int>> index_v = combine(nums.size(), i);
            vector<int> v;
            vector<vector<int>>::iterator itt;
            for(itt=index_v.begin(); itt!=index_v.end(); itt++)
            {
                vector<int>::iterator it;
                vector<int> tmp = *itt;
                v.clear();
                for(it=tmp.begin(); it!=tmp.end(); it++)
                {
                    v.push_back(nums[*it - 1]);
                }
                out.push_back(v);
            }
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