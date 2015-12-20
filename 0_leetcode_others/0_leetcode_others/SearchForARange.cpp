class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto p = std::equal_range(nums.begin(), nums.end(), target);
        if(p.second - p.first <= 0) return vector<int>{-1, -1};
        return vector<int>{p.first-nums.begin(), p.second - nums.begin() -1};
    }
};