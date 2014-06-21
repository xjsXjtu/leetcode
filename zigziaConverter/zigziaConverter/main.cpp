#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    string convert(string s, int nRows)
    {
        if(nRows == 1)
        {
            return s;
        }

         int nUnit = nRows + nRows - 2;
         int nCol = (s.size() + nUnit - 1) / nUnit;

         string out;
         
         // r = 0
         for(int c=0; c<nCol; c++)
         {
            out.push_back(s[c * nUnit]);
         }

         // r = 1...nRows -2
         for(int r=1; r<nRows-1; r++)
         {
             int c = 0;
             for(c=0; c<nCol-1; c++)
             {
                out.push_back(s[c * nUnit + r]);
                out.push_back(s[c * nUnit + nUnit - r]);
             }
             if(c * nUnit + r < s.size())
             {
                out.push_back(s[c * nUnit + r]);
             }
             if(c * nUnit + nUnit - r < s.size())
             {
                out.push_back(s[c * nUnit + nUnit - r]);
             }
         }

         // r = nRows - 1
         int r = nRows - 1, c=0;
         for(c=0; c<nCol-1; c++)
         {
            out.push_back(s[c * nUnit + r]);
         }
         if(c * nUnit + r < s.size())
         {
            out.push_back(s[c * nUnit + r]);
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