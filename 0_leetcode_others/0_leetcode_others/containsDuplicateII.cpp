#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <utility>
#include <assert.h>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> umap;
        for (int i = 0; i < nums.size(); i++)
        {
            std::unordered_map<int, int>::iterator it = umap.find(nums[i]);
            if ( it == umap.end())
            {
                umap.insert({ nums[i], i });
            }
            else
            {
                if (i - it->second <= k)
                    return true;
                else
                    it->second = i;
            }
        }
        return false;
    }
};

int main()
{
    Solution s;
    int test_a1[] = { 10, 1, 2, 7, 6, 1, 5 };
    vector<int> test_vec1(test_a1, test_a1 + sizeof(test_a1) / sizeof(int));
    cout << s.containsNearbyDuplicate(test_vec1, 3);
    system("pause");
    return 0;
}