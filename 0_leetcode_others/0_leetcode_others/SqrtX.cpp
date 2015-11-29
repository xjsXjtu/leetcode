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
    int mySqrt(int x) {
        // binary search in [0, x]
        int64_t mid;
        int low = 0, high = x; // when in doubt, use int64_t
        while(low <= high)
        {
            mid = low + ((high - low) >> 1);
            if(mid * mid == x) return mid;
            if(mid * mid < x)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        // for array searching task, return -1 here: means not found.
        return high; // very easy to make mistake by returning mid
    }
    int mySqrt_newton(int x) 
    {
        assert(x >= 0);
        if(x == 0)
            return 0;
        // Newton method
        // f(w) = w^2 - x = 0
        // w_new = (w_old + x/w_old)/2
        // init: w0 = x/2
        double w_old = -1.0, w_new = x / 2.0;
        while(abs(w_new - w_old) > 0.1)
        {
            w_old = w_new;
            w_new = (w_old + x / w_old) / 2;
            cout << w_new << endl;
        }
        return (int)(w_new);
    }
};

void test(int x)
{
    Solution s;
    cout << "sqrt(" << x << ") = " << s.mySqrt(x) << endl;
}

int main()
{
    test(0);
    test(1);
    test(2);
    test(9);
    test(10);
    test(1579267599); // math.sqrt(1579267599) = 39739.99998741822

    test(3);

    system("pause");
    return 0;
}