#include <vector>
#include <iostream>
#include <stdlib.h>
using namespace std;

#define PAUSE   system("pause")

inline vector<int> vectorConstruct(int *a, int size)
{
    vector<int> out(a, a + size);
    return out;
}

inline void printV(vector<int> v)
{
    vector<int>::iterator it;
    cout << "[";
    if(v.size() == 0)
    {
        cout << "]" << endl;
        return;
    }
    for(it=v.begin(); it != v.end() - 1; it++)
    {
        cout << *it << ", ";
    }
    cout << *it << "]" << endl;
}
inline void printVV(vector<vector<int>> out)
{
    vector<vector<int>>::iterator it_vec_vec;
    for(it_vec_vec = out.begin(); it_vec_vec != out.end(); it_vec_vec++)
    {
        vector<int>::iterator it;
        vector<int> v = *it_vec_vec;
        printV(v);
    }
}