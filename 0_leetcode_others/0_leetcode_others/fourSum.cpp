#include <vector>
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
	vector<vector<int>> fourSum(vector<int>& nums, int target)
	{
        vector<int> modnums(nums);
		sort(modnums.begin(), modnums.end());
		
		set<vector<int>> sout;
		vector<vector<int>> vout;
		int first = 0, second = 1, len=modnums.size();
		if(len < 4)
			return vout;

		for(first=0; first<len-3; first++)
		{
			if(first>0 && modnums[first] == modnums[first-1])
				continue;

			for(second = first + 1; second < len - 2; second++)
			{
				if(second> first + 1 && modnums[second] == modnums[second-1])
					continue;

				int left = second + 1, right = len -1;
				while(left<right)
				{
					int sum = modnums[first] + modnums[second] + modnums[left] + modnums[right];
					if(sum == target )
					{
						vector<int> tmp(4, 0); // {0, 0, 0, 0}
						tmp[0] = modnums[first];
						tmp[1] = modnums[second];
						tmp[2] = modnums[left];
						tmp[3] = modnums[right];
						sout.insert(tmp);
						left++;
						right--;
					}
					else if(sum < target)
					{
						left++;
					}
					else
					{
						right--;
					}
				}
			}
		}

		set<vector<int>>::iterator itset;
		for(itset=sout.begin(); itset!=sout.end(); itset++)
		{
			vout.push_back(*itset);
		}
		return vout;
    }
};

int main()
{
	int test_a1[] = {1, 0, -1, 0, -2, 2};
	vector<int> test_vec1(test_a1, test_a1 + sizeof(test_a1)/sizeof(int));
	int test_tar1 = 9;


	Solution s;
	vector<vector<int>> out = s.fourSum(test_vec1, 0);
	vector<vector<int>>::iterator it;
	for(it=out.begin(); it!=out.end(); it++)
	{
		vector<int> v = *it;
		cout<< v[0] << ", " << v[1] << ", " << v[2] << ", " << v[3] << endl;
	}
	
	system("pause");
	return 0;
}