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
    bool canJump(vector<int>& nums) {
        int max_arrive = 0;
        int size = nums.size();
        for(int i=0; i<size && i <= max_arrive && max_arrive < size - 1; i++)
        {
            max_arrive = max<int>(max_arrive, i + nums[i]);
        }
        return max_arrive >= size - 1;
    }
};