#include <string>
#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        string path;
        vector<string> out;
        rec(s, 4, path, &out);
        return out;
    }
private:
    void rec(const string &s, const int n, const string &path, vector<string> *out)
    {
        if(n==0)
        {
            if(s.size() == 0)
            {
                out->push_back(path.substr(1, path.size()-1));
            }
            return;
        }
        if((int)s.size() - 1 >= n - 1)
        {
            rec(s.substr(1, s.size()-1), n - 1, path + "." + s.substr(0, 1), out);
        }
        if((int)s.size() - 2 >= n - 1 && s[0] != '0')
        {
            rec(s.substr(2, s.size()-2), n-1, path + "." + s.substr(0, 2), out);
        }
        if((int)s.size() - 3 >= n - 1 && s[0] != '0' && std::stoi(s.substr(0, 3)) < 256)
        {
            rec(s.substr(3, s.size()-3), n-1, path + "." + s.substr(0, 3), out);
        }
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
    //test("0");
    //test("0000");
    test("1111");
    test("010010");
    test("25525511135");

    system("pause");
    return 0;
}