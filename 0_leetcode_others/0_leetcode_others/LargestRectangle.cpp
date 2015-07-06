#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std; 

class Solution {
private:
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
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.size() == 0)
            return 0;
        vector<int> hist(matrix[0].size(), 0);
        int row = matrix.size(), col = matrix[0].size();
        int max_area = 0;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (matrix[i][j] == '1')
                {
                    hist[j] += 1;
                }
                else
                {
                    hist[j] = 0;
                }
            }
            max_area = max<int>(max_area, largestRectangleArea(hist));
        }
        return max_area;
    }
};

int main()
{
    Solution s;
    vector<vector<char>> matrix;
    cout << s.maximalRectangle(matrix) << endl;
    matrix.push_back(vector<char>(3, '1'));
    cout << s.maximalRectangle(matrix) << endl;
    system("pause");
    return 0;
}