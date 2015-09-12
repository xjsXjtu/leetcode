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

template<typename T>
inline void printV(vector<T> v)
{
    vector<T>::iterator it;
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

template<typename T>
inline void printVV(vector<vector<T>> out)
{
    vector<vector<T>>::iterator it_vec_vec;
    for(it_vec_vec = out.begin(); it_vec_vec != out.end(); it_vec_vec++)
    {
        vector<T>::iterator it;
        vector<T> v = *it_vec_vec;
        printV(v);
    }
}