#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
private:
    bool recursive(vector<int>& s, vector<int>::iterator begin, vector<int>& path, set<vector<int>>& out, int target)
    {
        if(target == 0)
        {
            out.insert(path);
            return true;
        }
        else if(target < 0 || begin == s.end())
        {
            return false;
        }

        recursive(s, begin+1, path, out, target);               // not include *begin
        path.push_back(*begin);
        recursive(s, begin+1, path, out, target - (*begin));    // include *begin
        path.pop_back();
        return false;
    }
public:
    vector<vector<int>> combinationSumII(vector<int>& candidates, int target) 
    {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> out;
        set<vector<int>> out_set;
        vector<int> path;
        recursive(candidates, candidates.begin(), path, out_set, target);
        for(set<vector<int>>::iterator its = out_set.begin(); its!=out_set.end(); its++)
        {
            out.push_back(*its);
        }
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
    int test_a1[] = {10,1,2,7,6,1,5};
    int target1 = 8;
	vector<int> test_vec1(test_a1, test_a1 + sizeof(test_a1)/sizeof(int));
    Solution s;
    vector<vector<int>> out = s.combinationSumII(test_vec1, target1);
    printResult(out);
    system("pause");
    return 0;
}