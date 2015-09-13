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
private:
    struct ResRem{
        int64_t res;
        int64_t rem;
        ResRem(int64_t rs=0, int64_t rm=0):res(rs), rem(rm){}
    };

public:
    int divide(int dividend, int divisor) {
        return divide_3(dividend, divisor);
    }

private:
    // rec + umap: 12ms
    int divide_1(int dividend, int divisor) {
        assert(divisor != 0);
        bool oMinus = (dividend < 0) ^ (divisor < 0);
        int64_t dv64 = abs(static_cast<int64_t>(divisor)), dd64 = abs(static_cast<int64_t>(dividend));
        unordered_map<int64_t, ResRem> umap;
        int64_t out = rec(dd64, dv64, umap);
        out = oMinus ? -out : out;
        return max<int64_t>(INT_MIN, min<int64_t>(INT_MAX, out));
    }
    int64_t rec(int64_t &dd, int64_t dv, unordered_map<int64_t, ResRem> &umap)
    {
        if(dd < dv)
            return 0;
        if(dd == dv)
        {
            dd = 0;
            return 1;
        }
        if(umap.find(dd) != umap.end()) // already computed
        {
            int64_t ddb = dd;
            dd = umap[ddb].rem;
            return umap[ddb].res;
        }
        //cout << dd << endl;
        int64_t dd1 = dd >> 1, dd2 = dd - dd1;
        int64_t out = rec(dd1, dv, umap) + rec(dd2, dv, umap);
        if(dd1 + dd2 >= dv )
        {
            out++;
            dd1 -= dv;
        }
        umap.insert(std::pair<int64_t, ResRem>((int64_t)dd, ResRem(out, dd1 + dd2)));
        dd = dd1 + dd2;
        return out;
    }

    //Top -> Down, 12ms,  ref: https://github.com/leetcoders/LeetCode/blob/master/DivideTwoIntegers.h 
    int divide_2(int dividend, int divisor) {
        assert(divisor != 0);
        bool flag = (dividend < 0) ^ (divisor < 0);
        long long dividendll = abs((long long)dividend);
        long long divisorll = abs((long long)divisor);
        long long res = 0;
        long long d = divisorll, q = 1;
        while ((d << 1) <= dividendll) {
            d <<= 1;
            q <<= 1;
        }
        while (dividendll >= divisorll) {
            if (dividendll >= d) {
                dividendll -= d;
                res += q;
            }
            d >>= 1;
            q >>= 1;
        }
        if (flag == true) res = -res;
        if (res > INT_MAX) return INT_MAX;
        return res;
    }
    //bottom -> up, 8ms, ref: https://github.com/leetcoders/LeetCode/blob/master/DivideTwoIntegers.h 
    int divide_3(int dividend, int divisor) {
        assert(divisor != 0);
        bool flag = (dividend < 0) ^ (divisor < 0);
        long long Dividend = abs((long long)dividend);
        long long Divisor = abs((long long)divisor);
        long long res = 0;
        while (Dividend >= Divisor) {
            long long c = Divisor;
            for (int i = 0; (c << i) <= Dividend; ++i) {
                Dividend -= (c << i);
                res += (1 << i);
            }
        }
        if (flag == true) res = -res;
        if (res > INT_MAX) return INT_MAX;
        return res;
    }
};

int main()
{
    Solution s;
    cout << s.divide(0, 1) << endl;
    //cout << s.divide(1, 0) << endl;
    cout << s.divide(1, 1) << endl;
    cout << s.divide(5, 2) << endl;
    cout << s.divide(10, 5) << endl;
    cout << s.divide(10, -5) << endl;
    cout << s.divide(-10, 5) << endl;
    cout << s.divide(-10, -5) << endl;
    cout << s.divide(37, 3) << endl;
    
    cout << s.divide(2147483647, 2) << endl;
    cout << s.divide(2147483647, 1) << endl;

    cout << s.divide(-1010369383, -2147483648) << endl; // for int, -(-2147483648) = -2147483648

    cout << s.divide(-2147483648, -1) << endl;  // overflow
    cout << s.divide(-2147483648, 1) << endl;   // underflow

    system("pause");
    return 0;
}