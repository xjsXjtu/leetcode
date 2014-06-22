#include <iostream>
#include <assert.h>
using namespace std;

class Solution {
public:
    int reverse(int x)
    {
        long long out = 0;
        while(x)
        {
            out = out * 10 + x % 10;
            assert(out < INT_MAX && out > INT_MIN);
            x = x / 10;
        }
        if(x<0)
            return (int)-out;
        else
            return (int)out;
    }
};

int main()
{
    int x1 = 123;
    int x2 = -123;
    int x3 = 1000000003; // failed

    cout << INT_MAX << endl; 

    Solution s;
    cout << s.reverse(x3) << endl;

    system("pause");
    return 0;
}