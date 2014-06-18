#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n)
    {
        int *sorted = (int*)malloc(sizeof(int)*(m + n));
        int ia = 0, ib = 0;
        int i=0;
        double out = 0;
        while(ia<m || ib<n)
        {
            if(ib == n || (ia < m && A[ia] < B[ib]))
            {
                sorted[i] = A[ia];            
                ia++;
            }
            else
            {
                sorted[i] = B[ib];
                ib++;
            }
            i++;
        }
        if((m + n) % 2)
        {
            out = sorted[(m+n-1)>>1];
        }
        else
        {
            out = (sorted[(m+n-2)>>1] + sorted[(m+n)>>1]) / 2.;
        }
        free(sorted);
        return out;
    }
};

int main()
{
    int a1[] = {1, 3};
    int b1[] = {2};

    int a2[] = {1};
    int b2[] = {2};

    Solution s;
    cout << s.findMedianSortedArrays(a2, sizeof(a2)/sizeof(int), b2, sizeof(b2)/sizeof(int)) << endl;
    
    system("pause");
    return 0;
}