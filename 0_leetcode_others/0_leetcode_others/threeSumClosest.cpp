#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <utility>
#include <assert.h>
using namespace std;

class Solution 
{
public:
	int threeSumClosest(vector<int>& nums, int target)
	{
        vector<int> modnums(nums);
		sort(modnums.begin(), modnums.end());
		
		int out = modnums[0] + modnums[1] + modnums[2];
		int first = 0, len=modnums.size();
		for(first=0; first<len; first++)	
		{
			int left = first + 1, right=len - 1;
			while(left < right)
			{
				int diff = modnums[first] + modnums[left] + modnums[right] - target;
				if(abs(out - target) > abs(diff))
				{
					out = diff + target;
				}
				if(diff == 0)
					return out;
				else if(diff < 0)
					left++;
				else
					right--;
			}
		}
		return out;
    }
};

int main()
{
	int test_a1[] = {-1, 2, 1, -4};
	vector<int> test_vec1(test_a1, test_a1 + sizeof(test_a1)/sizeof(int));
	int test_tar1 = 9;


	Solution s;
	cout << s.threeSumClosest(test_vec1, 1) << endl;
	
	system("pause");
	return 0;
}