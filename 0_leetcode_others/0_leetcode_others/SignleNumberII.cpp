class Solution {
public:
    // ref: https://leetcode.com/discuss/56524/a-general-c-solution-for-these-type-problems 
    int singleNumber(vector<int>& nums) {
        vector<int> t(32);////Made a array contain 32 elements.
        int sz = nums.size();
        int i, j, n;
        for (i = 0; i < sz; ++i)
        {
            n = nums[i];
            for (j = 31; j >= 0; --j)
            {
                t[j] += n & 1;//Find the last digit.
                n >>= 1;
                if (!n)
                    break;
            }
        }
        int res = 0;
        for (j = 31; j >= 0; --j)
        {
            n = t[j] % 3;//"3" represents k times. 
            if (n)
                res += 1 << (31 - j);
        }
        return res;
    }
};