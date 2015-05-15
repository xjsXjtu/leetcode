#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
private:
    bool recursive(vector<int>& s, vector<int>::iterator begin, vector<int>& path, vector<vector<int>>& out, int target)
    {
        if(target == 0)
        {
            out.push_back(path);
            return true;
        }
        else if(target < 0 || begin == s.end())
        {
            return false;
        }

        int n = 0;
        while(n * (*begin) <= target)
        {
            for(int i=0; i<n; i++)
            {
                path.push_back(*begin);
            }
            recursive(s, begin+1, path, out, target - n * (*begin));
            for(int i=0; i<n; i++)
            {
                path.pop_back();
            }
            n++;
        }
        return false;
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> out;
        vector<int> path;
        recursive(candidates, candidates.begin(), path, out, target);
        return out;
    }
};

void printResult(vector<vector<int>> out)
{
    vector<vector<int>>::iterator it_vec_vec;
    for(it_vec_vec = out.begin(); it_vec_vec != out.end(); it_vec_vec++)
    {
        vector<int>::iterator it;
        vector<int> v = *it_vec_vec;
        cout << "[";
        for(it=v.begin(); it != v.end()-1; it++)
        {
            cout << *it << ", ";
        }
        cout << *it << "]" << endl;
    }
}
int main()
{
    int test_a1[] = {2, 3, 6, 7};
    int target1 = 7;
	vector<int> test_vec1(test_a1, test_a1 + sizeof(test_a1)/sizeof(int));
    Solution s;
    vector<vector<int>> out = s.combinationSum(test_vec1, target1);
    printResult(out);
    system("pause");
    return 0;
}