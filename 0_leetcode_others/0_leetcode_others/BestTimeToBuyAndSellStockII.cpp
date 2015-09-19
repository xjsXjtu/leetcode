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
        if(prices.size() <2) return 0;
        int max_prof = 0, size = prices.size(); 
        for(int i=1; i<size; i++)
        {
            if(prices[i] > prices[i-1])
                max_prof += prices[i] - prices[i-1];
        }
        return max_prof;
    }
};