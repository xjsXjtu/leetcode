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
        sort(nums.begin(), nums.end());
        vector<int> path;
        vector<vector<int>> out;
        int size = nums.size();
        for(int i=0; i<=size; i++)
        {
            rec(nums, 0, i, path, &out);
        }
        return out;
    }
private:
    void rec(vector<int>& nums, int start_pos, int subset_size, vector<int> path, vector<vector<int>> *out)
    {
        if(subset_size == 0)
        {
            out->push_back(path);
            return;
        }
        int size = nums.size();
        int last_pos = -1;
        for(int i=start_pos; i<=size-subset_size; i++) 
        {
            if(last_pos != -1 && nums[last_pos] == nums[i]) continue;
            last_pos = i;
            vector<int> path2(path);
            path2.push_back(nums[i]);
            rec(nums, i+1, subset_size-1, path2, out);
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