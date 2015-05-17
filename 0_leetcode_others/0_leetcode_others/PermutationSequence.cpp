#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
private:
    int factorial_tab[10];

public:
    Solution()
    {
        factorial_tab[0] =   1      ;   // 0!
        factorial_tab[1] =   1      ;   // 1!
        factorial_tab[2] =   2      ;   // 2!
        factorial_tab[3] =   6      ;   // 3!
        factorial_tab[4] =   24     ;
        factorial_tab[5] =   120    ;
        factorial_tab[6] =   720    ;
        factorial_tab[7] =   5040   ;
        factorial_tab[8] =   40320  ;
        factorial_tab[9] =   362880 ;
    }
    void core(int n, int k, vector<char> nums, string& path)
    {
        cout << "k, " << k << endl;
        if(n == 1)
        {
            path.push_back(nums[nums.size() - 1]);
            return;
        }
        int x = (k - 1) / factorial_tab[n-1];
        path.push_back(nums[nums.size() - n + x]);
        swap(nums[nums.size() - n + x], nums[nums.size() - n]);
        sort(nums.begin() + nums.size() - n + 1, nums.end());
        core(n-1, k - x * factorial_tab[n-1], nums, path);
    }
public:
    string getPermutation(int n, int k)
    {
        string path;
        vector<char> nums;
        for(int i=1; i<n+1; i++)
            nums.push_back(i + '0');
        core(n, k, nums, path);
        return path;
    }
};

int main()
{
    Solution s;
    cout << endl << s.getPermutation(3, 5) << endl;

    system("pause");
    return 0;
}

