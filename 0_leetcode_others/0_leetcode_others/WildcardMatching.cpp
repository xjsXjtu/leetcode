#include <string>
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

class Solution {
private: 
    int si_bak, pi_bak;
private:
    bool isMatchCore(const string& s, int si, const string &p, int pi)
    {
        if(si == s.length() && pi == p.length())    // both s and p arrive the end
            return true;
        if(si == s.length())                        // only s arrive the end
        {
            if(p.substr(pi, p.length() - pi) == string(p.length() - pi, '*'))
                return true;
            return false;
        }
        // if(pi == p.length())                    // if p arrive the end but s don't, p[pi] will be '\0',  the program will go backtracking

        if(p[pi] == '*')
        {
            while(p[pi] == '*') pi++;
            pi_bak = pi;
            si_bak = si;
        }
        else if(p[pi] == '?' || p[pi] == s[si])
        {
            pi++;  si++;
        }
        else
        {
            // not matched, need backtracking
            if(pi_bak == -1)
                return false;
            pi = pi_bak;
            si = ++si_bak;
        }
        return isMatchCore(s, si, p, pi);
    }
public:
    bool isMatch(string s, string p) 
    {
        si_bak = pi_bak = -1;
        return isMatchCore(s, 0, p, 0);
    }
};

/* 
 * answer by ChenHao
 */
bool isMatch(const char *s, const char *p) {

    const char *last_s = NULL; 
    const char *last_p = NULL;
    while( *s != '\0' ){
        if (*p=='*'){
            //skip the "*", and mark a flag
            p++;
            //edge case
            if (*p=='\0') return true;
            //use last_s and last_p to store where the "*" match starts.
            last_s = s;
            last_p = p;
        }else if (*p=='?' || *s == *p){
            s++; p++;
        }else if (last_s != NULL){ // check "last_s" to know whether meet "*" before
            // if meet "*" previously, and the *s != *p
            // reset the p, using '*' to match this situation
            p = last_p;
            s = ++last_s; 
        }else{
            // *p is not wildcard char, 
            // doesn't match *s, 
            // there are no '*' wildcard matched before
            return false;
        }
    }
    //edge case: "s" is done, but "p" still have chars.
    while (*p == '*') p++;
    return *p == '\0';
}

int main()
{
    Solution s;
    cout << "True => " << true << endl;
    cout << (isMatch("ab", "*?")   == true) << endl;

    cout << "(s.isMatch(aa,a)         == false) => " << (s.isMatch("aa","a")         == false) << endl;
    cout << "(s.isMatch(aa,aa)        == true ) => " << (s.isMatch("aa","aa")        == true ) << endl;
    cout << "(s.isMatch(aaa,aa)       == false) => " << (s.isMatch("aaa","aa")       == false) << endl;
    cout << "(s.isMatch(aa, *)        == true ) => " << (s.isMatch("aa", "*")        == true ) << endl;
    cout << "(s.isMatch(aa, a*)       ==  true) => " << (s.isMatch("aa", "a*")       ==  true) << endl;
    cout << "(s.isMatch(ab, ?*)       == true ) => " << (s.isMatch("ab", "?*")       == true ) << endl;
    cout << "(s.isMatch(ab, *?)       == true ) => " << (s.isMatch("ab", "*?")       == true ) << endl;
    cout << "(s.isMatch(aab, c*a*b)   == false) => " << (s.isMatch("aab", "c*a*b")   == false) << endl;
    system("pause");
    return 0;
}