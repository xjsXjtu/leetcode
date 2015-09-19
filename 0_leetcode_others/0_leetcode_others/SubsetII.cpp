#include <cassert>
#include <cstdint>

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
// #include <initializer_list>

#include "shared_functions.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        sort(nums.begin(), nums.end());
        int size = nums.size();
        for(int i=0; i<size+1; i++)
        {
            rec(nums, 0, i, path, res);
        }
        return res;
    }
private:
    void rec(vector<int>& nums, int start_pos, int subset_size, vector<int>& path, vector<vector<int>>& res)
    {
        if(subset_size == 0)
        {
            res.push_back(path);
            return;
        }
        int nsize = nums.size();
        assert(start_pos + subset_size <= nsize);
        int last_pos = -1;
        for(int i=start_pos; i<nsize-subset_size+1; i++)
        {
            if(last_pos != -1 && nums[i] == nums[last_pos]) continue;
            last_pos = i;
            path.push_back(nums[i]);
            rec(nums, i + 1, subset_size - 1, path, res);
            path.pop_back();
        }
    }
};

int test(int *a, int size)
{
    vector<int> v(a, a+size);
    Solution s;
    vector<vector<int>> res;
    res = s.subsetsWithDup(v);
    cout << "Input: ";
    printV<int>(v);
    cout << endl << "Output: " << endl;
    printVV<int>(res);
    cout << endl << endl;
    return 0;
}

int main()
{
    int a1[] = {1};
    test(a1, 0);
    test(a1, sizeof(a1)/sizeof(int));

    int a2[] = {1, 1};
    test(a2, sizeof(a2)/sizeof(int));

    int a3[] = {1, 2};
    test(a3, sizeof(a3)/sizeof(int));

    int a4[] = {1, 1, 2};
    test(a4, sizeof(a4)/sizeof(int));
    
    int a5[] = {1, 1, 2, 1, 2, 3};
    test(a5, sizeof(a5)/sizeof(int));
    system("pause");
    return 0;
}