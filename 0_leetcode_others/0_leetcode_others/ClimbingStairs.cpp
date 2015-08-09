class Solution {
public:
    int climbStairs(int n) {
        if(n<=2)
            return n;
        int an_2 = 1, an_1 = 2, an = 0;
        for(int i=3; i<=n; i++)
        {
            an = an_1 + an_2;
            an_2 = an_1;
            an_1 = an;
        }
        return an;
    }
};