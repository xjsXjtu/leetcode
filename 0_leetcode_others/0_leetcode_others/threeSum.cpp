#include <vector>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <utility>
#include <assert.h>

using namespace std;

class TestSet
{
public:
	void test_set()
	{
		set<pair<int, int>> s;
		s.insert(pair<int, int>(1, 2));
		s.insert(pair<int, int>(2, 3));
		s.insert(pair<int, int>(1, 2));

		cout << "[TestSet==>pair] set contains:" << endl;
		set<pair<int, int>>::iterator it;
		for(it=s.begin(); it != s.end(); it++)
		{
			cout << "( " << get<0>(*it) << ", " << get<1>(*it) << " )" << endl;
		}

		// test vector<int>
		set<vector<int>> svec;
		svec.insert(vector<int>(1, 2)); // {2}
		svec.insert(vector<int>(1, 3)); // {3}
		svec.insert(vector<int>(1, 2)); // {2}
		svec.insert(vector<int>(3, 2)); // {2, 2, 2}
		svec.insert(vector<int>(3, 4)); // {4, 4, 4}

		cout << "[TestSet==>vector<int>] set contains:" << endl;
		set<vector<int>>::iterator itsetvec;
#if 0
		for(itsetvec=svec.begin(); itsetvec!=svec.end(); itsetvec++)
		{
			vector<int>::iterator itvec;
			vector<int> v = *itsetvec;
			for(itvec=v.begin(); itvec!=v.end(); itvec++)
			{
				cout << *itvec << ", ";
			}
			cout << endl;
		}
#else
		for(itsetvec=svec.begin(); itsetvec!=svec.end(); itsetvec++)
		{
			vector<int>::iterator itvec;
			for(itvec=((vector<int>)(*itsetvec)).begin(); itvec!=(*itsetvec).end(); itvec++)
			{
				cout << *itvec << ", ";
			}
			cout << endl;
		}
#endif

		return;
	}
};

class Solution 
{
private:
	// end not included
    set<pair<int, int>> twoSumForSorted(vector<int> &sorted_numbers, int start, int end, int target) 
    {
        int len = sorted_numbers.size();
		assert(start >= 0 && end <= len);

        set<pair<int, int>> out;
		int left = start, right = end - 1;

		while(left < right)
		{
			if(sorted_numbers[left] + sorted_numbers[right] == target)
			{
				out.insert(pair<int, int>(sorted_numbers[left], sorted_numbers[right]));
				left++;
				right--;
			}
			else if(sorted_numbers[left] + sorted_numbers[right] < target)
			{
				left++;
			}
			else
			{
				right--;
			}
		}

        return out;
    }
	
public:
	vector<vector<int>> threeSum(vector<int>& nums) 
	{
        vector<int> modnums(nums);
		sort(modnums.begin(), modnums.end());
		
		vector<vector<int>> out;
		int first = 0, len=modnums.size();
		for(first=0; first<len; first++)
		{
			if(first>0 && modnums[first] == modnums[first-1])
				continue;

			set<pair<int, int>> other = twoSumForSorted(modnums, first + 1, len, -modnums[first]);
			if(other.size() > 0)
			{
				set<pair<int, int>>::iterator it;
				for(it=other.begin(); it!=other.end(); it++)
				{
					vector<int> v(3, 0); // {0, 0, 0}
					v[0] = modnums[first];
					v[1] = get<0>(*it);
					v[2] = get<1>(*it);
					out.push_back(v);
				}
			}
		}
		return out;
    }
};

int main()
{
#if 0
	TestSet ts;
	ts.test_set();
#else
	int test_a1[] = {-1, 0, 1, 2, -1, -4};
	vector<int> test_vec1(test_a1, test_a1 + sizeof(test_a1)/sizeof(int));
	int test_tar1 = 9;


	Solution s;
	vector<vector<int>> out = s.threeSum(test_vec1);
	vector<vector<int>>::iterator it;
	for(it=out.begin(); it!=out.end(); it++)
	{
		vector<int> v = *it;
		cout<< v[0] << ", " << v[1] << ", " << v[2]<< endl;
	}
#endif
	
	system("pause");
	return 0;
}