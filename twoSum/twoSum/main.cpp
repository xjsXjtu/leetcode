#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
private:
    typedef struct{
        int ind;
        int val;
    }ind_val_t;

private:
    static bool isSmaller(const ind_val_t a, const ind_val_t b)
    {
        return a.val < b.val;
    }

public:
    vector<int> twoSum(vector<int> &numbers, int target) 
    {
        int len = numbers.size();

        vector<ind_val_t> iv_vec(len);
        for(int i=0; i<len; i++)
        {
            iv_vec[i].ind = i;
            iv_vec[i].val = numbers[i];
        }

        sort(iv_vec.begin(), iv_vec.end(), isSmaller);

        /* xi: the last element that < target/2 */
        /* xj: xi + 1, the first elemet that >= target/2 */
        int xi, xj;
        for(int i=0; i<len; i++)
        {
            if(iv_vec[i].val * 2 >= target)
            {
                xi = max(i - 1, 0);
                xj = xi + 1;
                break;
            }
        }

        vector<int> out(2);
        if(iv_vec[xj].val == iv_vec[xj+1].val && iv_vec[xj].val + iv_vec[xj+1].val == target)
        {
            out[0] = iv_vec[xj].ind + 1;
            out[1] = iv_vec[xj+1].ind + 1;
            if(out[0] > out[1])
            {
                swap(out[0], out[1]);
            }
            return out;
        }
        while(xi>=0 && xj<len)
        {
            int sum = iv_vec[xi].val + iv_vec[xj].val;
            if(sum == target)
            {
                out[0] = iv_vec[xi].ind + 1;
                out[1] = iv_vec[xj].ind + 1;
                if(out[0] > out[1])
                {
                    swap(out[0], out[1]);
                }
                return out;
            }
            else if(sum < target)
            {
                xj++;
            }
            else
            {
                xi--;
            }
        }

        out[0] = out[1] = 0;
        return out;
    }
};

int main()
{
	int test_a1[] = {2, 7, 9, 11};
	vector<int> test_vec1(test_a1, test_a1 + sizeof(test_a1)/sizeof(int));
	int test_tar1 = 9;

    int test_a2[] = {230,863,916,585,981,404,316,785,88,12,70,435,384,778,887,755,740,337,86,92,325,422,815,650,920,125,277,336,221,847,168,23,677,61,400,136,874,363,394,199,863,997,794,587,124,321,212,957,764,173,314,422,927,783,930,282,306,506,44,926,691,568,68,730,933,737,531,180,414,751,28,546,60,371,493,370,527,387,43,541,13,457,328,227,652,365,430,803,59,858,538,427,583,368,375,173,809,896,370,789};
    vector<int> test_vec2(test_a2, test_a2 + sizeof(test_a2)/sizeof(int));
	int test_tar2 = 542;

    int test_a3[] = {0,4,3,0};
    vector<int> test_vec3(test_a3, test_a3 + sizeof(test_a3)/sizeof(int));
	int test_tar3 = 0;

    int test_a4[] = {5,75,25};
    vector<int> test_vec4(test_a4, test_a4 + sizeof(test_a4)/sizeof(int));
	int test_tar4 = 100;
    
    int test_a5[] = {2,1,9,4,4,56,90,3};
    vector<int> test_vec5(test_a5, test_a5 + sizeof(test_a5)/sizeof(int));
	int test_tar5 = 8;
    

	Solution s;
	vector<int> out = s.twoSum(test_vec5, test_tar5);
	cout << out[0] << " " << out[1] << endl;

	
	system("pause");
	return 0;
}