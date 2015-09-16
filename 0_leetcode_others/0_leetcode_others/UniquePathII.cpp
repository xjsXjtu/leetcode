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
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        assert(obstacleGrid.size() > 0 && obstacleGrid[0].size()>0);
        if(obstacleGrid[0][0] == 1) return 0;
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = 1;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(obstacleGrid[i][j]==1)
                {
                    dp[i][j] = 0;
                    continue;
                }
                if(i>0)
                {
                    dp[i][j] += dp[i-1][j];    
                }
                if(j>0)
                {
                    dp[i][j] += dp[i][j-1];
                }
            }
        }
        return dp[m-1][n-1];
    }
};


void test(int )
{
    Solution s;
    //cout << "m,n = " << m << ", " << n << ": " << s.uniquePathsWithObstacles(m ,n) << endl;
    return;
}

int main()
{
    // Fuck VS2012 cannot support C++11 init list !!
    int a[][1] = {{0}};
    test
    Solution s;

    system("pause");
    return 0;
}