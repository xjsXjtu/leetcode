#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s)
    {
        int outl = 0;
        string outs = "";
        for(int i=0; i<s.size(); i++)
        {
            int templ1 = 0;
            while((i - templ1 >= 0) && (i + templ1 < s.size()) && (s[i - templ1] == s[i + templ1]))
            {
                templ1++;
            }
            if(outl < templ1 * 2 - 1)
            {
                outl = templ1 * 2 - 1;
                outs = s.substr(i - templ1 + 1, outl);
            }

            int templ2 = 0;
            while((i - templ2 >= 0) && (i + 1 + templ2 < s.size()) && (s[i - templ2] == s[i + 1 + templ2]))
            {
                templ2++;
            }
            if(outl < templ2 * 2)
            {
                outl = templ2 * 2;
                outs = s.substr(i - templ2 + 1, outl);
            }
        }
        return outs;
    }
};

int main()
{
    string s1 = "123bab93";
    string s2 = "a";
    string s3 = "";
    string s4 = "aa";
    
    Solution s;
    cout << s.longestPalindrome(s1) << endl;

    system("pause");
    return 0;
}