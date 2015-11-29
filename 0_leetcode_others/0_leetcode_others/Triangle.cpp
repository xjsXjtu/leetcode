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

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle[triangle.size() -1].size();
        vector<int> up_level_dp(n, 0), cur_level_dp(n, 0);
        cur_level_dp[0] = up_level_dp[0] = triangle[0][0];
        for(int i=1; i<n; i++)
        {
            cur_level_dp[0] = up_level_dp[0] + triangle[i][0];
            cur_level_dp[i] = up_level_dp[i-1] + triangle[i][i];
            for(int j=1; j<i; j++)
            {
                cur_level_dp[j] = min<int>(up_level_dp[j-1], up_level_dp[j]) + triangle[i][j];
            }
            std::swap(up_level_dp, cur_level_dp);
        }
        return *(std::min_element(up_level_dp.begin(), up_level_dp.end()));
    }
};

int main()
{
    Solution s;
    vector<vector<int>> in(2, vector<int>(2, 1));
    in[0][0] = 1;
    in[1][0] = 2;
    in[1][1] = 3;

    cout << s.minimumTotal(in);
}