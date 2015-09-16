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
    int minPathSum(vector<vector<int>>& grid) {
        assert(grid.size() > 0 && grid[0].size()>0);
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = grid[0][0];
        // If-else should move outside of the for-for loop
        // So as to improve performance.
        // Sorry, I don't care for the time being. 
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(i>0 && j>0)
                {
                    dp[i][j] = min<int>(dp[i-1][j], dp[i][j-1]) + grid[i][j];
                }
                else if(i==0 && j!=0)
                {
                    dp[i][j] = dp[i][j-1] + grid[i][j];    
                }
                else if(j==0 && i!=0)
                {
                    dp[i][j] = dp[i-1][j] + grid[i][j];
                }
            }
        }
        return dp[m-1][n-1];
    }
};