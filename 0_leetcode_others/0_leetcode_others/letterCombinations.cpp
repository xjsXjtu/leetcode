#include <string>
#include <vector>
#include <assert.h>
#include <iostream>
using namespace std;

class Solution {
private:
	string mapping[10];
	
public:
	Solution()
	{
		mapping[0] = " "	;	// 0
		mapping[1] = ""		;	// 1
		mapping[2] = "abc"	;	// 2
		mapping[3] = "def"	;	// 3
		mapping[4] = "ghi"	;	// 4
		mapping[5] = "jkl"	;	// 5
		mapping[6] = "mno"	;	// 6
		mapping[7] = "pqrs"	;	// 7
		mapping[8] = "tuv"	;	// 8
		mapping[9] = "wxyz"	;	// 9
	}
		
private:
	void recursive(string pre, string left_digits, vector<string> &out)
	{
		int len = left_digits.size();
		assert(len > 0);
		int num = left_digits[0] - '0';
		assert( num <= 9 && num >= 0);
		string num_string = mapping[num];

		if(len == 1)
		{
			for(int i=0; i<num_string.size(); i++)
			{
				out.push_back(pre + num_string.substr(i, 1));
			}
			return;
		}
		else
		{
			for(int i=0; i<num_string.size(); i++)
			{
				recursive(pre + num_string.substr(i, 1), left_digits.substr(1, len-1), out);
			}
		}
	}

public:
    vector<string> letterCombinations(string digits) 
	{
        vector<string> out;
		if(digits.size() == 0)
			return out;
		recursive("", digits, out);
		return out;
    }
};

int main()
{
	string in = "23";
	Solution s;
	vector<string> out = s.letterCombinations(in);
	vector<string>::iterator it;
	for(it=out.begin(); it!=out.end(); it++)
	{
		cout << *it << endl;
	}

	system("pause");
	return 0;
}