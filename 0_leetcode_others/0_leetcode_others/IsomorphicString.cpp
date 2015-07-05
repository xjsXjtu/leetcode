#include <unordered_map>
#include <unordered_set>
#include <string>
#include <cassert>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        assert(s.size() == t.size());
        int size = s.size();
        unordered_map<char, char> umap_s2t;
        unordered_set<char> uset_t;
        for (int i = 0; i < size; i++)
        {
            if (umap_s2t.find(s[i]) == umap_s2t.end())
            {
                if (uset_t.find(t[i]) == uset_t.end())
                {
                    umap_s2t.insert({ s[i], t[i] });
                    uset_t.insert(t[i]);
                }   
                else
                    return false;
            }
            else
            {
                if (umap_s2t[s[i]] != t[i])
                    return false;
            }
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