#include <iostream>
#include <math.h>
using namespace std;

class Solution {
public:
    int getBits(long long x)
    {
        int out = 0;
        for(x = abs(x); x > 0; x = x / 10)
            out++;
        return out;
    }
    bool isPalindrome(int x)
    {
        if(x < 0)
            return false;
        if(x == 0)
            return true;

        long long y = x;
        int bits = getBits(y);
        int exp = pow(double(10), bits -1);

        for(; bits > 1; bits -=2, y /= 10, exp /= 100)
        {
            int yl = y % 10;
            int yh = y / exp % 10;
            if(yl != yh)
                return false;
        }
        return true;
    }
};

int main()
{
    int x[] = {0, 1, -1, 123, 121, 1234, 1221, 122222221};
    int x1 = -2147483648;
    int x2 = -2147447412;
    Solution s;
    for(int i=0; i<sizeof(x)/sizeof(int); i++)
    {
        cout << x[i] << ": " << s.isPalindrome(x[i]) << endl;
    }
    cout << x1 << ": " << s.isPalindrome(x1) << endl;
    cout << x2 << ": " << s.isPalindrome(x2) << endl;

    system("pause");
    return 0;
}