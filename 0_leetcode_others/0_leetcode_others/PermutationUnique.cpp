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
    vector<vector<int>> permuteUnique(vector<int> &num) {
        vector<bool> used(num.size(), false);
        vector<int> path;
        vector<vector<int>> res;
        rec(num, used, path, res);
        return res;
    }
private:
    void rec(vector<int>& num, vector<bool> &used, vector<int> &path, vector<vector<int>>& res)
    {
        if(path.size() == num.size())
        {
            res.push_back(path);
            return;
        }
        unordered_set<int> uset;
        int size = num.size();
        for(int i=0; i<size; i++)
        {
            if(used[i] || uset.find(num[i]) != uset.end()) continue;
            uset.insert(num[i]);

            path.push_back(num[i]);
            used[i] = true;
            rec(num, used, path, res);
            path.pop_back();
            used[i] = false;
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