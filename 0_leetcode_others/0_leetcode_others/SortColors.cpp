class Solution {
public:
    void sortColors(vector<int>& nums) {
        int count[3] = {0};
        if(nums.size() == 0)
            return;
        int size = nums.size();
        for(int i=0; i<size; i++)
        {
            count[nums[i]]++;
        }
        for(int i=0; i<count[0]; i++)
            nums[i] = 0;
        for(int i=count[0]; i<count[0]+count[1]; i++)
            nums[i] = 1;
        for(int i=count[0]+count[1]; i<size; i++)
            nums[i] = 2;
        return;
    }
};