#include <vector>
#include <iostream>
#include "shared_functions.h"
using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result(1 << n, 0);
        int len = 1 << n;
        for (int i = 0; i < len; ++i)
            result[i] = (i >> 1) ^ i;
        return result;
    }
};

int main()
{
    Solution s;
    printV(s.grayCode(3));
    PAUSE;
    return 0;
}