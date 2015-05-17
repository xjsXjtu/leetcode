#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <assert.h>
using namespace std;

class Solution {
public:
    // ref from: http://harrifeng.github.io/algo/leetcode/regular-expression-matching.html 
    bool isMatch(string s, string p) 
    {
        int slen = s.length(), plen = p.length();
        if (plen == 0) {
            return slen == 0;
        }
        if (plen == 1) {
            return slen == 1
                && (p[0] == '.' || p[0] == s[0]) ;
        }
        // plen i bigger than 1 here
        if (p[1] == '*') {
            // match 0 p[0]
            if (isMatch(s, p.substr(2, plen -2))) {
                return true;
            }
            // match 1...n p[0]
            return slen > 0
                && (p[0] == '.' || s[0] == p[0])
                && isMatch(s.substr(1, slen -1), p);
        } else {
            return slen > 0
                && (p[0] == '.' || s[0] == p[0])
                && isMatch(s.substr(1, slen -1), p.substr(1, plen -1));
        }
    }
};

int main()
{
    Solution s;
    cout << "True => " << true << endl;

    cout << "(s.isMatch(aa,a)         == false) => " << (s.isMatch("aa","a")         == false) << endl;
    cout << "(s.isMatch(aa,aa)        == true ) => " << (s.isMatch("aa","aa")        == true ) << endl;
    cout << "(s.isMatch(aaa,aa)       == false) => " << (s.isMatch("aaa","aa")       == false) << endl;
    cout << "(s.isMatch(aa, .*)       ==  true) => " << (s.isMatch("aa", ".*")       ==  true) << endl;
    cout << "(s.isMatch(ab, .*)       == true ) => " << (s.isMatch("ab", ".*")       == true ) << endl;
    cout << "(s.isMatch(aab, c*a*b)   == true) => " << (s.isMatch("aab", "c*a*b")   == true ) << endl;
    cout << "(s.isMatch(aab, b*b)   == false) => " << (s.isMatch("aab", "b*b")   == false ) << endl;
    system("pause");
    return 0;
}