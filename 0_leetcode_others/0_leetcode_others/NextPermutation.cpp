class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size() <= 1) return;
        int size = nums.size();
        int i=0;
        for(i=size-1; i>0; i--)
        {
            if(nums[i] > nums[i-1]) break;
        }
        
        if(i==0)
        {
            std::reverse(nums.begin(), nums.end());
        }
        else
        {
            int j=0;
            for(j=size-1; j>=i; j--)
            {
                if(nums[j] > nums[i-1]) break;
            }
            std::swap(nums[j], nums[i-1]);
            std::reverse(nums.begin() + i, nums.end());
        }
        return;
    }
};