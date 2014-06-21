#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    string convert(string s, int nRows)
    {
        if(nRows == 1)
            return s;

         int nUnit = nRows + nRows - 2;
         int nCol = (s.size() + nUnit - 1) / nUnit;
         string out;
         
         for(int r=0; r<nRows; r++)
         {
             int i=0;
             for(i=0; i + r < s.size(); i += nUnit)
             {
                 out.push_back(s[i + r]);
                 if(r>0 && r<nRows-1 && i + nUnit - r < s.size())
                 {
                    out.push_back(s[i + nUnit - r]);
                 }
             }
         }

         return out;
    }
};

int main()
{
    string s1="012345678";
    string s2="";

    Solution s;

    cout << "r=2: " << s.convert(s2, 1) << endl;
    cout << "r=2: " << s.convert(s2, 2) << endl;
    cout << "r=3: " << s.convert(s1, 3) << endl;
    cout << "r=4: " << s.convert(s1, 4) << endl;

    system("pause");
    return 0;
}