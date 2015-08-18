#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        if(s.size() == 0)
            return 0;
        if(s.size() == 1)
            return s[0] > '0' && s[0] <= '9';
        
        // handle '0' and other invalid char's
        for(int i=0; i<s.size(); i++)
        {
            if(s[i] < '0' || s[i] > '9')
                return 0;
            if(s[i] == '0')
            {
                if(i == 0)
                    return 0;
                if(s[i - 1] == '1' || s[i - 1] == '2')
                {
                    s.erase(i - 1, 2);
                    i = i - 2; // there's i++ in the for loop
                }
                else
                {
                    return 0;
                }
            }
        }
        if(s.size() == 0)
            return 1;

        // DP on others
        vector<int> decodeNum(s.size());
        decodeNum[0] = 1;
        if(s.size() >= 2)
            decodeNum[1] = (s[0] - '0') * 10 + s[1] - '0' > 26 ? 1 : 2;
        int size = s.size();
        for(int i=2; i<size; i++)
        {
            int x = (s[i - 1] - '0') * 10 + (s[i] - '0');
            if(x <= 26)
            {
                decodeNum[i] = decodeNum[i - 1] + decodeNum[i - 2];
            }
            else
            {
                decodeNum[i] = decodeNum[i - 1];
            }
        }
        return decodeNum[size - 1];        
    }
};

int main()
{
    Solution s;
    string str;
    str = "0";      cout << str << ": " << s.numDecodings(str) << endl;
    str = "1";      cout << str << ": " << s.numDecodings(str) << endl;
    str = "10";     cout << str << ": " << s.numDecodings(str) << endl;
    str = "100";    cout << str << ": " << s.numDecodings(str) << endl;
    str = "12";     cout << str << ": " << s.numDecodings(str) << endl;
    str = "123";    cout << str << ": " << s.numDecodings(str) << endl;
    str = "1234";   cout << str << ": " << s.numDecodings(str) << endl;
    str = "4321";   cout << str << ": " << s.numDecodings(str) << endl;
    
    system("pause");
    return 0;
}