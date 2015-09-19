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
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> path;
        rec(s, 0, path, res);
        return res;
    }
private:
    void rec(string &s, int start_pos, vector<string> &path, vector<vector<string>>& res)
    {
        if(start_pos == s.size())
        {
            res.push_back(path);
            return;
        }
        int size = s.size();
        for(int i=1; i<=size-start_pos; i++)
        {
            if(!isPalindrome(s, start_pos, start_pos + i - 1)) continue;
            path.push_back(s.substr(start_pos, i));
            rec(s, start_pos + i, path, res);
            path.pop_back();
        }
    }
    bool isPalindrome(string &s, int start, int end)
    {
        assert(start>=0 && end<s.size());
        int size = end - start + 1;
        int loops = size / 2;
        for(int i=0; i<loops; i++)
        {
            if(s[start + i] != s[end - i]) return false;
        }
        return true;
    }
};

void test(string s)
{
    Solution sl;
    cout << "Input: " << s << endl;
    cout << "Output: " << endl;
    vector<vector<string>> res = sl.partition(s);
    printVV<string>(res);
    cout << endl;
    return ;
}

int main()
{
    test("");
    test("a");
    test("aa");
    test("aaaa");
    
    test("ab");
    test("abababa");
   
    system("pause");
    return 0;
}