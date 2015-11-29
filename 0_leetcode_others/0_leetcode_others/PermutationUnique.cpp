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
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int size = nums.size();
        vector<bool> used(size, false);
        vector<vector<int>> out;
        vector<int> path;
        rec(nums, &used, path, &out);
        return out;
    }
private:
    void rec(const vector<int>& nums, vector<bool> *used, const vector<int> path, vector<vector<int>> *out)
    {
        if(path.size() == nums.size())
        {
            out->push_back(path);
            return;
        }
        int size = nums.size();
        unordered_set<int> uset;
        for(int i=0; i<size; i++)
        {
            if(used->at(i) || uset.find(nums[i]) != uset.end()) continue;
            uset.insert(nums[i]);
            used->at(i) = true;
            vector<int> path2(path);
            path2.push_back(nums[i]);
            rec(nums, used, path2, out);
            used->at(i) = false;
        }
    }
};

int test(int *a, int size)
{
    vector<int> v(a, a+size);
    Solution s;
    vector<vector<int>> res;
    res = s.permuteUnique(v);
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