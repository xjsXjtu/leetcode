class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        auto plower = std::lower_bound(nums.begin(), nums.end(), target);
        return plower - nums.begin();
    }
};