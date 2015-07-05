#include <map>
#include <unordered_map>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> anagrams(vector<string>& strs) {
        vector<string> out;
        unordered_map<string, int> umap_key2count;
        multimap<string, string> mmap_key2string; // key is sorted string
        for (int i = 0; i < strs.size(); i++)
        {
            string key = strs[i];
            sort(key.begin(), key.end());
            if (umap_key2count.find(key) == umap_key2count.end())
                umap_key2count.insert({ key, 1 });
            else
                umap_key2count[key] += 1;
            mmap_key2string.insert({ key, strs[i] });
        }

        for (multimap<string, string>::iterator it = mmap_key2string.begin(); it != mmap_key2string.end(); it++)
        {
            if (umap_key2count[it->first] >= 2)
                out.push_back(it->second);
        }
        return out;
    }
};

int main()
{
    vector<string> sv;
    sv.push_back("tea");
    sv.push_back("and");
    sv.push_back("ate");
    sv.push_back("eat");
    sv.push_back("den");
    Solution s;
    vector<string> sout = s.anagrams(sv);
    for (int i = 0; i < sout.size(); i++)
        cout << sout[i] << endl;
    system("pause");
    return 0;

}