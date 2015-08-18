#include <string>
#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
private:
    int calNum(string s)
    {
        int out = 0;
        for(int i=0; i<s.size(); i++)
        {
            assert(s[i] >= '0' && s[i] <= '9');
            out = out * 10 + s[i] - '0';
        }
        return out;
    }

    void rec(string s, vector<string> &out, string path, int n)
    {
        assert(n >= 1);
        if(s.size() < n)
            return;
        if(n == 1)
        {
            if(s.size() <= 0 || s.size() >= 4)
                return;
            if( s[0] == '0' && s.size() > 1)
                return;
            if(calNum(s) > 255)
                return;
            out.push_back(path + s);
            return;
        }
        rec(s.substr(1, s.size() - 1), out, path + s.substr(0, 1) + ".", n - 1);
        if(s[0] != '0' && s.size() >= n + 1 && calNum(s.substr(0, 2)) <= 255)
        {
            rec(s.substr(2, s.size() - 2), out, path + s.substr(0, 2) + ".", n - 1);
        }
        if(s[0] != '0' && s.size() >= n + 2 && calNum(s.substr(0, 3)) <= 255)
        {
            rec(s.substr(3, s.size() - 3), out, path + s.substr(0, 3) + ".", n - 1);
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> out;
        string path;
        rec(s, out, path, 4);
        return out;
    }
};

void printVecStr(vector<string> in)
{
    for(int i=0; i<in.size(); i++)
    {
        cout << "\"" << in[i] << "\", ";
    }
    cout << endl;
}

void test(string s)
{
    Solution sl;
    cout << s << ": "; printVecStr(sl.restoreIpAddresses(s));
}
int main()
{
    test("0");
    test("0000");
    test("1111");
    test("010010");
    test("25525511135");

    system("pause");
    return 0;
}