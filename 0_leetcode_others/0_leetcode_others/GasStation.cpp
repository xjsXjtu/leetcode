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
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        assert(gas.size() == cost.size());
        int left_gas = -1;
        int start_pos = -1;
        int size = gas.size();
        int sum = 0;
        for(int i=0; i<size; i++)
        {
            int diff = gas[i] - cost[i];
            if(left_gas < 0)
            {
                left_gas = diff;
                start_pos = i;
            }
            else
            {
                left_gas += diff;
                // start_pos = i;
            }
            sum += diff;
        }
        if(sum < 0) return -1;
        else return start_pos;
    }
};

void test(int *gas, int *cost, int size)
{
    vector<int> g(gas, gas + size), c(cost, cost + size);
    Solution s;
    printV<int>(g);
    printV<int>(c);
    cout << "Out: " << s.canCompleteCircuit(g, c) << endl << endl;
}

int main()
{
    int g1[] = {1, 2};
    int c1[] = {1, 2};
    test(g1, c1, 2);

    
    int g2[] = {1, 2};
    int c2[] = {2, 1};
    test(g2, c2, 2);

    
    int g3[] = {1, 2, 3, 4, 5};
    int c3[] = {3, 4, 5, 1, 2};
    test(g3, c3, 5);

    system("pause");
    return 0;
}