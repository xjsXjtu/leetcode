#include <unordered_map>
#include <unordered_set>
#include <string>
#include <cassert>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) return false;

        const int MAXCHAR = 256;
        char maps[MAXCHAR] = { 0 }, mapt[MAXCHAR] = { 0 };
        //memset(maps, 0, sizeof(maps));
        //memset(mapt, 0, sizeof(mapt));

        for (int i = 0; i<s.size(); i++){
            if (maps[s[i]] == 0 && mapt[t[i]] == 0){
                maps[s[i]] = t[i];
                mapt[t[i]] = s[i];
                continue;
            }
            if (maps[s[i]] == t[i] && mapt[t[i]] == s[i]) {
                continue;
            }
            return false;
        }
        return true;
    }
};

int main()
{
    Solution s;
    
    cout << s.isIsomorphic("ab", "aa") << endl;
    cout << s.isIsomorphic("ab", "aa") << endl;
    cout << s.isIsomorphic("egg", "add") << endl;
    cout << s.isIsomorphic("foo", "bar") << endl;
    cout << s.isIsomorphic("paper", "title") << endl;
    system("pause");
    return 0;
}