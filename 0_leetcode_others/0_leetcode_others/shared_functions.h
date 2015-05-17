#include <vector>
#include <iostream>
using namespace std;

inline vector<int> vectorConstruct(int *a, int size)
{
    vector<int> out(a, a + size);
    return out;
}

inline void printVV(vector<vector<int>> out)
{
    vector<vector<int>>::iterator it_vec_vec;
    for(it_vec_vec = out.begin(); it_vec_vec != out.end(); it_vec_vec++)
    {
        vector<int>::iterator it;
        vector<int> v = *it_vec_vec;
        cout << "[";
        for(it=v.begin(); it != v.end()-1; it++)
        {
            cout << *it << ", ";
        }
        cout << *it << "]" << endl;
    }
}