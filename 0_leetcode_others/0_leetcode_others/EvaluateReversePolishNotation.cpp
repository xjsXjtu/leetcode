#include <iostream>
#include <vector>
#include <queue>
#include <cassert>
#include <stack>
#include <string>
#include <cstdlib>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
		if(tokens.size() == 0)
			return 0;
		bool flag = true;
		int op1, op2;
		stack<int> s;
		char buffer[32] = {0};
		for(int i=0; i<tokens.size(); i++)
		{
			if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/")
			{
				int op1 = s.top(); s.pop();
				int op2 = s.top(); s.pop();
				switch(tokens[i][0])
				{
				case '+':
					op2 += op1;
					break;
				case '-':
					op2 -= op1;
					break;
				case '*':
					op2 *= op1;
					break;
				case '/':
					assert(op1 != 0);
					op2 /= op1;
					break;
				default:
					assert(0);
					break;
				}
				s.push(op2);
			}
			else
			{
				s.push(stoi(tokens[i].c_str()));
			}
		}
		assert(s.size() == 1);
		return (s.top());
    }
};

int main()
{
	Solution s;
	vector<string> tok;
	tok.push_back("0");
	tok.push_back("3");
	tok.push_back("/");
	cout << s.evalRPN(tok) << endl;

	tok.clear();
	tok.push_back("0");
	tok.push_back("-3");
	tok.push_back("+");
	// cout << s.evalRPN(tok) << endl;

	tok.clear();
	tok.push_back("4");
	tok.push_back("13");
	tok.push_back("5");
	tok.push_back("/");
	tok.push_back("+");
	// cout << s.evalRPN(tok) << endl;

	// 1 * ((5/2) + (1-3)) = 0
	tok.clear();
	tok.push_back("1");
	tok.push_back("5");
	tok.push_back("2");
	tok.push_back("/");
	tok.push_back("1");
	tok.push_back("3");
	tok.push_back("-");
	tok.push_back("+");
	tok.push_back("*");
	//cout << s.evalRPN(tok) << endl;


	system("pause");
	return 0;

}
