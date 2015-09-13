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
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator == 0) return "0";
        bool flag = (numerator<0) ^ (denominator<0);
        int64_t dd = abs(int64_t(numerator));
        int64_t dv = abs(int64_t(denominator));
        int64_t res = dd / dv;
        char buffer[128] = {'\0'};
        sprintf(buffer, "%lld", res);
        string out = flag ? "-" : "";
        out.append(string(buffer));
        
        int64_t rem = dd % dv;
        if(rem == 0) return out;
        out.push_back('.');

        unordered_map<int64_t, int> umap;
        string dec = "";
        while(umap.find(rem) == umap.end())
        {
            dec.push_back('0' + rem * 10 / dv);
            umap[rem] = dec.size() - 1;
            rem = rem * 10 % dv;
        }
        if(rem == 0) return out.append(string(dec.begin(), dec.begin() + umap[rem]));
        out.append(string(dec.begin(), dec.begin() + umap[rem]));
        out.append("(");
        out.append(string(dec.begin() + umap[rem], dec.end()));
        out.append(")");
        return out;        
    }
};

void test(int dd, int dv)
{
    Solution s;
    cout << dd << "/" << dv << " = " << s.fractionToDecimal(dd, dv) << endl;
}

int main()
{
    test(1, 1);
    test(4, 2);
    test(1, 3);
    test(5, 6);
    test(1, 17);
    test(19, 33);

    test(-1, 3);
    test(1, -3);
    test(-1, -3);
    
    test(INT_MAX, 1);
    test(INT_MIN, 1);

    // missing considerations
    test(1, 5); 

    system("pause");
    return 0;
}