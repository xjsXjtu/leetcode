#include <string>
#include <map>
#include <iostream>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
        if(s.size() == 0)
        {
            return 0;
        }

        int maxlen = 1;
        map<char, int> mp;
        //printf("map['a'] = %d\n", mp['a']);
        mp[s[0]] = 1;
        int k = 1; // k = index + 1
        for(int i=1; i<s.size(); i++)
        {
            if(mp[s[i]])
            {
                int j=0;
                for(j=k-1; j<mp[s[i]]; j++)
                {
                    mp.erase(s[j]);
                }
                k = j + 1;
            }
            mp[s[i]] = i + 1;
            maxlen = max(maxlen, i-k+2);            
        }
        return maxlen;
    }
};

int main()
{
    string s1 = "abcabcbb";
    Solution s;
    cout << s.lengthOfLongestSubstring(s1) << endl;

    system("pause");
    return 0;
}