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
using namespace std;

class Solution {
public:
    // 4ms
    double myPow(double x, int n) {
        if(n==0)
            return 1.0;
        if(n<0)
            x = 1.0/x;
        n = abs(n);
        double res = 1.0;
        while(n>0)
        {
            double xx = x;
            for(int nn=1; nn <= n; nn <<= 1)
            {
                res *= xx;
                xx *= xx;
                n -= nn;
            }
        }
        return res;
    }
    // rec: 4ms
    // ref: https://github.com/leetcoders/LeetCode/blob/master/Pow%28x%2Cn%29.h
    double pow(double x, int n) {
        if (x < 0) return (n % 2 == 0) ? pow(-x, n) : -pow(-x, n);
        if (x == 0 || x == 1) return x;
        if (n < 0) return 1.0 / pow(x, -n);
        if (n == 0) return 1.0;
        
        double half = pow(x, n / 2);
        if (n % 2 == 0) return half * half;
        else return x * half * half;
    }
};

void test(double x, int n)
{
    Solution s;
    cout << "pow(" << x << ", " << n << ") = " << s.myPow(x, n) << endl;
}
int main()
{
    test(2.0, 0);
    test(2.0, 11);
    test(2.0, -11);
   
    test(11.0, 5);
    test(11.0, -50);
    system("pause");
    return 0;
}