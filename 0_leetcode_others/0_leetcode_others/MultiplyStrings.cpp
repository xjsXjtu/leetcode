#include <string>
#include <iostream>
#include <cassert>

using namespace std;

class Solution {
public:
    string add(string num1, string num2)
    {
        string out = "";
        int len1 = num1.size(), len2 = num2.size();
        assert(len1 > 0 && len2 > 0);

        int carry = 0;
        while(len1 > 0 && len2 > 0)
        {
            len1--; len2--;
            int n1 = num1[len1] - '0';
            int n2 = num2[len2] - '0';
            int o = (carry + n1 + n2 ) % 10;
            carry = (carry + n1 + n2 ) / 10;
            out.push_back(o + '0');
        }
        while(--len1 >= 0)
        {
            int n1 = num1[len1] - '0';
            int o = (carry + n1) % 10;
            carry = (carry + n1) / 10;
            out.push_back(o + '0');
        }
        while(--len2 >= 0)
        {
            int n2 = num2[len2] - '0';
            int o = (carry + n2) % 10;
            carry = (carry + n2) / 10;
            out.push_back(o + '0');
        }
        if(carry)
        {
            out.push_back(carry + '0');
        }
        reverse(out.begin(), out.end());
        return out;
    }
    
    // 36 ms
    string multiply_1(string num1, string num2) {
        string out = "0";
        int len1 = num1.size(), len2 = num2.size();
        if(num1 == "0" || num2 == "0")
            return "0";
        assert(len1 > 0 && len2 > 0);

        int k = 0;
        for(int i=len2-1; i>=0; i--) // num2[i]
        {
            string out_tmp = "";
            int n2 = num2[i] - '0';
            int carry = 0;
            for(int j=len1-1; j>=0; j--) // num1[j]
            {
                int n1 = num1[j] - '0';
                int o  = (carry + n1 * n2) % 10;
                carry  = (carry + n1 * n2) / 10;
                out_tmp.push_back(o + '0');
            }
            if(carry)
            {
                out_tmp.push_back(carry + '0');
            }
            reverse(out_tmp.begin(), out_tmp.end());
            out_tmp.append(string(k, '0'));
            k++;
            out = add(out, out_tmp);
        }
        return out;
    }

    // 8 ms!! ref: leetcode github https://github.com/leetcoders/LeetCode/blob/master/MultiplyStrings.h
    string multiply_2(string num1, string num2) {
        int N = num1.size(), M = num2.size();
        string res(N+M, '0');
        for (int i = N - 1; i >= 0; --i)
        {
            int carry = 0;
            for (int j = M - 1; j >= 0; --j)
            {
                int sum = carry + (res[i+j+1] - '0') + 
                          (num1[i] - '0') * (num2[j] - '0');
                res[i+j+1] = sum % 10 + '0';
                carry = sum / 10;
            }
            res[i] += carry;
        }
        while (res.size() > 1 && res[0] == '0')
            res.erase(res.begin());
        return res;
    }

    string multiply(string num1, string num2)
    {
        return multiply_2(num1, num2);
    }
};

int main()
{
    Solution s;
    cout << s.add("15", "987") << endl;         // 2002
    cout << s.add("987", "15") << endl;         // 2002
    cout << s.multiply("15", "987") << endl;    // 14805

    system("pause");
    return 0;
}
