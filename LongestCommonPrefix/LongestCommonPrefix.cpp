// Problem:
//		Write a function to find the longest common prefix string amongst an array of strings.
// Author: XIONG Jinshui

#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) 
	{
		if(strs.size() == 0)
			return "";

		int short_len = strs[0].size();
		for(int i=1; i<strs.size(); i++)
		{
			short_len = min<int>(short_len, strs[i].size());
		}
		if(short_len == 0)
			return "";

		int ret = 0;
		int str_num = strs.size();		
		for(int i=0; i<short_len; i++)
		{
			for(int j=1; j<str_num; j++)
			{
				if(strs[j][i] != strs[0][i])
				{
					return strs[0].substr(0, ret);
				}
			}
			ret++;
		}
		return strs[0].substr(0, short_len);
    }
};

int main()
{
	Solution s;
	vector<string> st;
	st.push_back("aa");
	st.push_back("a");
	//st.push_back("c");
	cout << s.longestCommonPrefix(st) << endl;
	system("pause");
}