#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    // ref: http://www.cnblogs.com/lichen782/p/leetcode_Largest_Rectangle_in_Histogram.html
    int largestRectangleArea(vector<int>& height) {
        stack<int> index_of_increasing_height_stack;
        vector<int> h(height.begin(), height.end());
        h.push_back(0);
        int max_area = 0;
        for (int i = 0; i < h.size();)
        {
            if (index_of_increasing_height_stack.empty() || h[index_of_increasing_height_stack.top()] <= h[i])
            {
                index_of_increasing_height_stack.push(i);
                i++;
            }
            else
            {
                int ind = index_of_increasing_height_stack.top();
                index_of_increasing_height_stack.pop();
                int width = index_of_increasing_height_stack.empty() ? i : i - 1 - index_of_increasing_height_stack.top();
                max_area = max<int>(max_area, h[ind] * width);
            }
        }
        return max_area;
    }
};

int main()
{
    int a[] = { 2, 1, 5, 6, 2, 3 };
    vector<int> av(a, a + sizeof(a) / sizeof(int));
    Solution s;
    cout << s.largestRectangleArea(av) << endl;
    system("pause");
    return 0;
}