#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxArea(vector<int> &height) {
        int out = 0;
        for(int i=0; i<height.size() - 1; i++)
        {
            for(int j=i+1; j<height.size(); j++)
            {
                int t = (j - i) * min(height[i], height[j]);
                out = out > t ? out : t;
            }
        }
        return out;
    }
};

int main()
{
    int a1[] = {3, 4, 2, 1};
    vector<int> v1(a1, a1 + sizeof(a1) / sizeof(int));

    Solution s;
    cout << s.maxArea(v1) << endl;

    system("pause");
    return 0;
}