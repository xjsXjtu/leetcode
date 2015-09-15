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
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        if(size == 0) return 0;

        int dup_num = 0;
        int iback=0, ifront = 0, idst = 0;
        while(iback < size)
        {
            ifront = iback + 1;
            while(ifront < size && nums[iback] == nums[ifront])
            {
                ifront++;
            }
            if(ifront - iback > 2)
            {
                dup_num += ifront - iback - 2;
                nums[idst] = nums[iback];
                nums[idst + 1] = nums[iback + 1];
                iback = ifront;
                idst += 2;
            }
            else
            {
                for(int i=iback; i<ifront; i++)
                {
                    nums[idst] = nums[iback];
                    idst++;
                    
                }
                iback = ifront;
            }
        }
        nums.erase(nums.begin() + idst, nums.end());
        return size - dup_num;
    }
};

int test(int *a, int size)
{
    vector<int> v(a, a+size);
    Solution s;
    cout << "Input: ";
    printV<int>(v);
    
    int out = s.removeDuplicates(v);
    cout << "Output = " << out << ": ";
    printV<int>(v);
    cout << endl;
    return out;
}

int main()
{
    int out;
    int a1[] = {0};
    out = test(a1, 0); // test empty
    out = test(a1, sizeof(a1)/sizeof(int));

    int a2[] = {0, 0};
    out = test(a2, sizeof(a2)/sizeof(int));

    
    int a3[] = {0, 0, 0};
    out = test(a3, sizeof(a3)/sizeof(int));

    
    int a4[] = {0, 0, 0, 0};
    out = test(a4, sizeof(a4)/sizeof(int));

    
    int a5[] = {0, 0, 0, 1, 1, 1, 1, 2, 2};
    out = test(a5, sizeof(a5)/sizeof(int));

    system("pause");
    return 0;
}