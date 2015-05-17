#include <vector>
#include <iostream>
#include "shared_functions.h"
using namespace std;

class Solution {
private:
    void recursive(int n, vector<int> &out)
    {
        

    }
public:
    vector<int> grayCode(int n) 
    {
        vector<int> out, out2;
        if(n == 0)
        {
            return vector<int>(1, 0);
        }
        if(n == 1)
        {
            out.resize(2);
            out[0] = 0;
            out[1] = 1;
            return out;
        }
        out2 = grayCode(n - 1);
        int len2 = out2.size();
        out.resize(len2 * 2);
        for(int i=0; i < len2; i++)
        {
            out[i] = out2[i];
        }
        int add = 1 << (n - 1);
        for(int i=0; i<len2; i++)
        {
            out[len2 + i] = out[len2 - 1 - i] + add;
        }
        return out;
    }
};

int main()
{
    Solution s;
    printV(s.grayCode(3));
    PAUSE;
    return 0;
}