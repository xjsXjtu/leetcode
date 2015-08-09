class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        int dup_num = 0;
        int i = 0;
        for(int j=1; j<size; j++)
        {
            if(nums[i] == nums[j])
            {
                dup_num++;
            }
            else
            {
                i++;
                nums[i] = nums[j];
            }
        }
        return size - dup_num;
    }
};