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
    int maxSubArray(vector<int>& nums) {
        assert(nums.size() > 0);
        if(nums.size() == 1) return nums[0];
        int max_sum = nums[0], max_pre = max_sum;
        for(int i=1; i<nums.size(); i++)
        {
            max_pre = max<int>(max_pre + nums[i], nums[i]);
            max_sum = max<int>(max_sum, max_pre);
        }
        return max_sum;
    }
};

int test(int *a, int size)
{
    vector<int> v(a, a+size);
    Solution s;
    printV<int>(v);
    cout << "\tout = " << s.maxSubArray(v) << endl << endl;
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