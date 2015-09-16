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

#include "shared_functions.h"

using namespace std;


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() < 2) return 0;
        int min_prev = prices[0];
        int max_prof = 0;
        for(int i=1; i<prices.size(); i++)
        {
            min_prev = min<int>(prices[i-1], min_prev);
            max_prof = max<int>(prices[i] - min_prev, max_prof);
        }
        return max_prof;
    }
};

int test(int *a, int size)
{
    vector<int> v(a, a+size);
    Solution s;
    printV<int>(v);
    cout << "\tout = " << s.maxProfit(v) << endl << endl;
    return 0;
}

int main()
{
    int a1[] = {0};
    // test(a1, 0);
    test(a1, 1);

    int a2[] = {1, -2};
    test(a2, sizeof(a2)/sizeof(int));

    int a3[] = {-1, 2};
    test(a3, sizeof(a3)/sizeof(int));

    int a4[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    test(a4, sizeof(a4)/sizeof(int));

    system("pause");
    return 0;

}