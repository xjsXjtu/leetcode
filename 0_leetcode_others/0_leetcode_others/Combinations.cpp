#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "shared_functions.h"
using namespace std;

class Solution {
private:
    void permuteCore(int n, int k, int start, vector<int>& path, vector<vector<int>>& out)
    {
        if(path.size() == k)
        {
            out.push_back(path);
            return;
        }
        for(int i=start; i<n-k+2+path.size(); i++)
        {
            path.push_back(i);
            permuteCore(n, k, i+1, path, out);
            path.pop_back();
        }
    }
public:
    // C(n, k) (n >= K)
    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>> out;
        vector<int> path;
        permuteCore(n, k, 1, path, out);
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

