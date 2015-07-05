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
        unordered_map<char, char> umap_t2s;
        for (int i = 0; i < size; i++)
        {
            // actually it's a one-one mapping
            if (umap_s2t.find(s[i]) == umap_s2t.end() && umap_t2s.find(t[i]) == umap_t2s.end())
            {
                umap_s2t.insert({ s[i], t[i] });
                umap_t2s.insert({ t[i], s[i] });
            }
            else if (umap_s2t[s[i]] != t[i] || umap_t2s[t[i]] != s[i])
            {
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