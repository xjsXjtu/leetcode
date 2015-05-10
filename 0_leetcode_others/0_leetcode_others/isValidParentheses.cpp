#include <string>
#include <stack>
#include <map>
#include <iostream>
using namespace std;

class Solution {
private:
	map<char, char> mapping;
public:
	Solution()
	{
		mapping[')'] = '(';
		mapping[']'] = '[';
		mapping['}'] = '{';
	}
public:
    bool isValid(string s) {
        stack<char> st;
		string::iterator it;
		for(it=s.begin(); it!=s.end(); it++)
		{
			if(*it == '(' || *it == '[' || *it == '{')
			{
				st.push(*it);
			}
			else if(*it == ')' || *it == ']' || *it == '}')
			{
				if(st.empty() || mapping[*it] != st.top())
					return false;
				else
					st.pop();
			}
		}
		if(st.empty())
			return true;
		return false;
    }
};

int main()
{
	Solution s;
	cout << s.isValid("(([]))");
	cout << s.isValid("([)]");
	system("pause");
	return 0;
}