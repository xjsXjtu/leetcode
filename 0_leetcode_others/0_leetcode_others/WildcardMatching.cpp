#include <string>
#include <iostream>
using namespace std;

class Solution {
private: 
    bool isMatchCore(string s, string p)
    { 
        if(p == "" && s == "")
            return true;
        if(s == "")
            return false;
        if(s.compare(p) == 0 || p == "*")
            return true;

        if(p[0] == '?' || p[0] == s[0])
            return isMatchCore(s.substr(1, s.length()-1), p.substr(1, p.length()-1));
        if(p[0] == '*')
        {
            int ch_start = 1;
            while(p[ch_start] == '*') ch_start++;
            int ch_end = ch_start;
            while(p[ch_end] != '*') ch_end++;
            int len = ch_end - ch_start;
            string chp = p.substr(ch_start, ch_end - ch_start);
            int i1 = -1;
            do
            {
                i1++;
                if(i1 + len > s.length())
                    return false;
            }while(s.substr(i1, len).compare(chp) != 0);

            return isMatchCore(s.substr(i1+len, s.length() - i1 - len), p.substr(ch_end, p.length() - ch_end)) 
                || isMatchCore(s.substr(i1+len, s.length() - i1 - len), p);

        }
        return false;
    }
public:
    bool isMatch(string s, string p) 
    {
        if(p == "" && s == "")
            return true;
        if(s == "")
            return false;

        // remove duplicated '*'
        int dup_stars = 0;
        int plen = p.length();
        for(int i=1; i<p.length(); i++)
        {
            if(p[i-1] == '*' && p[i] == '*')
            {
                p[i-1] = 0;
                dup_stars++;
            }
        }
        for(int i=0, j=0; j<plen; i++, j++)
        {
            while(p[j]==0) j++;
            p[i] = p[j];
        }

        // remove head and tail char's
        int pre_deletes=0, post_deletes=0;
        int slen = s.length();
        plen -= dup_stars;
        while(pre_deletes < plen && pre_deletes < slen && p[pre_deletes] != '*'&& p[pre_deletes] != '?')
        {
            if(s[pre_deletes] != p[pre_deletes])
                return false;
            pre_deletes++;
        }
        s = s.substr(pre_deletes, slen - pre_deletes);
        p = p.substr(pre_deletes, plen - pre_deletes);
        slen = s.length();
        plen = p.length();
        while(post_deletes < plen && post_deletes < slen && p[plen - 1 - post_deletes] != '*' && p[plen - 1 - post_deletes] != '?')
        {
            if(s[slen - 1 - post_deletes] != p[plen - 1 - post_deletes])
                return false;
            post_deletes++;
        }
        
        s = s.substr(0, slen - post_deletes);
        p = p.substr(0, plen - post_deletes);
        cout << "s: " << s << "\t\tp:" << p << endl;
        return isMatchCore(s, p);
    }
};

int main()
{
    Solution s;
    cout << "True => " << true << endl;
    cout << "(s.isMatch(aa,a)         == false) => " << (s.isMatch("aa","a")         == false) << endl;
    cout << "(s.isMatch(aa,aa)        == true ) => " << (s.isMatch("aa","aa")        == true ) << endl;
    cout << "(s.isMatch(aaa,aa)       == false) => " << (s.isMatch("aaa","aa")       == false) << endl;
    cout << "(s.isMatch(aa, *)        == true ) => " << (s.isMatch("aa", "*")        == true ) << endl;
    cout << "(s.isMatch(aa, a*)       ==  true) => " << (s.isMatch("aa", "a*")       ==  true) << endl;
    cout << "(s.isMatch(ab, ?*)       == true ) => " << (s.isMatch("ab", "?*")       == true ) << endl;
    cout << "(s.isMatch(aab, c*a*b)   == false) => " << (s.isMatch("aab", "c*a*b")   == false) << endl;
    cout << s.isMatch("babaaababaabababbbbbbaabaabbabababbaababbaaabbbaaab", "***bba**a*bbba**aab**b") << endl;
    cout << s.isMatch("bbbbbbbabbaabbabbbbaaabbabbabaaabbababbbabbbabaaabaab", "b*b*ab**ba*b**b***bba") << endl;
    cout << s.isMatch("aaaabaaaabbbbaabbbaabbaababbabbaaaababaaabbbbbbaabbbabababbaaabaabaaaaaabbaabbbbaababbababaabbbaababbbba", "*****b*aba***babaa*bbaba***a*aaba*b*aa**a*b**ba***a*a*") << endl;
    cout << s.isMatch("bbaaaabaaaaabbabbabbabbababaabababaabbabaaabbaababababbabaabbabbbbbbaaaaaabaabbbbbabbbbabbabababaaaaa", "******aa*bbb*aa*a*bb*ab***bbba*a*babaab*b*aa*a****") << endl;
    system("pause");
    return 0;
}