#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int numTrees(int n) {
        return numTrees_2(n);
    }
private:
    // DP
    int numTrees_2(int n)
    {
        if(n <= 1) return n;
        vector<int> dp(n + 1, 0);
        dp[0] = 0;
        dp[1] = 1;
        for(int i=2; i<=n; i++)
        {
            dp[i] += 2 * dp[i-1];
            for(int j=2; j<=i-1; j++)
                dp[i] += dp[j-1] * dp[i-j];
        }
        return dp[n];
    }

    // Recursive: Time Limited Exceed.
    // Many overlap sub-problem exists. 
    int numTrees_1(int n) {
        return rec(1, n);
    }
    int rec(int left, int right)
    {
        if(left > right)
        {
            return 0;
        }
        if(left == right)
        {
            return 1;
        }
        int out = 0;
        for(int i=left; i<=right; i++)
        {
            int left_size = rec(left, i-1);
            int right_size = rec(i+1, right);
            if(left_size == 0) 
                out += right_size;
            else if(right_size == 0) 
                out += left_size;
            else 
                out += right_size * left_size;
        }
        return out;
    }
};

int main()
{
    Solution s;
    cout <<  s.numTrees(0) << endl;;
    cout <<  s.numTrees(1) << endl;;
    cout <<  s.numTrees(3) << endl;;
    cout <<  s.numTrees(4) << endl;;

    system("pause");
    return 0;
}