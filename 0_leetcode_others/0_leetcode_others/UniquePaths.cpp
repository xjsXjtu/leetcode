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
    int uniquePaths(int m, int n) {
        assert(m>0 && n>0);
        vector<vector<int>> dp(m, vector<int>(n, 1));
        dp[0][0] = 1;
        for(int i=1; i<m; i++)
        {
            for(int j=1; j<n; j++)
            {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};

void test(int m, int n)
{
    Solution s;
    cout << "m,n = " << m << ", " << n << ": " << s.uniquePaths(m ,n) << endl;
    return;
}

int main()
{
    test(1, 1);
    test(1, 2);
    test(2, 1);
    test(2, 2);
    test(3, 3);
    system("pause");
    return 0;
}