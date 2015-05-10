#include <string>
#include <vector>
#include <set>
#include <iostream>
using namespace std;

class Solution {
private:
	void recursivePath(int x, int y, int n, string& path, vector<string>& out)
	{
		if(x == n && y == n)
		{
			out.push_back(path);
			return;
		}
		else
		{
			string path_bak(path);
			if(x + 1 <= n)
			{
				path.push_back('(');
				recursivePath(x+1, y, n, path, out);
			}
			if(y + 1 <= n && y + 1 <= x)
			{
				path = path_bak;
				path.push_back(')');
				recursivePath(x, y+1, n, path, out);
			}
		}
	}
public:
    vector<string> generateParenthesis(int n) 
	{
		vector<string> out;
		string path = "";
		recursivePath(0, 0, n, path, out);
		return out;
    }
};

int main()
{
	Solution s;
	vector<string> out = s.generateParenthesis(3);
	vector<string>::iterator it;
	for(it=out.begin(); it!=out.end(); it++)
	{
		cout << *it << endl;
	}
	system("pause");
	return 0;
}