#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) 
	{
		int len = numbers.size();
		for(int i=0; i<len; i++)
		{
		    int sub = target - numbers[i];
			for(int j=i+1; j<len; j++)
			{
				if(numbers[j] == sub)
				{
					vector<int> out(2);
					out[0] = i + 1;
					out[1] = j + 1;
					return out;
				}
			}
		}
    }
};

int main()
{
	int test_a1[] = {2, 7, 9, 11};
	vector<int> test_vec1(test_a1, test_a1 + sizeof(test_a1)/sizeof(int));
	int test_tar1 = 9;

	Solution s;
	vector<int> out = s.twoSum(test_vec1, test_tar1);
	cout << out[0] << " " << out[1] << endl;
	
	system("pause");
	return 0;
}