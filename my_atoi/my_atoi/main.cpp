#include <iostream>
#include <math.h>
using namespace std;

class Solution {
public:
    int atoi(const char *str)
    {
        int i=0;
        int neg =  1;
        
        for(i=0; str[i] == '\t' || str[i] == ' '; i++); // filt space or Tab

        if(str[i] == '-')
        {
            neg = -1;
            i++;
        }
        else if(str[i] == '+')
        {
            neg = 1;
            i++;
        }

        long long out = 0;
        for(; str[i] >= '0' && str[i] <= '9'; i++)
        {
            out = out * 10 + str[i] - '0';
        }

        int exp = 0;
        if(str[i] == 'e' || str[i] == 'E')
        {
            for(i++; str[i] >= '0' && str[i] <= '9'; i++)
            {
                exp = exp * 10 + str[i] - '0';
            }
        }
        
        out = neg * out * pow(double(10), exp);
        if(out > INT_MAX)
        {
            return INT_MAX; // overflow
        }
        else if(out < INT_MIN)
        {
            return INT_MIN; // underflow
        }
        return out;
    }
};

int main()
{
    char s0[] = "   123"; // missing input 1
    char s1[] = "123";
    char s2[] = "-123";
    char s21[] = "+123"; // missing intput 2
    char s3[] = "-123e3";
    char s4[] = "123E3";
    char s5[] =  "123E30"; // overflow
    char s6[] = "-123E30"; // underflow
    char s7[] = "-123a46"; // missing input 3

    Solution s;
    cout << s0 << ": " << s.atoi(s0) << "ref: " << atoi(s0) << endl;
    cout << s1 << ": " << s.atoi(s1) << "ref: " << atoi(s1) << endl;
    cout << s2 << ": " << s.atoi(s2) << "ref: " << atoi(s2) << endl;
    cout << s21 << ": " << s.atoi(s21) << "ref: " << atoi(s21) << endl;
    cout << s3 << ": " << s.atoi(s3) << "ref: " << atoi(s3) << endl;
    cout << s4 << ": " << s.atoi(s4) << "ref: " << atoi(s4) << endl;
    cout << s5 << ": " << s.atoi(s5) << "ref: " << atoi(s5) << endl;
    cout << s6 << ": " << s.atoi(s6) << "ref: " << atoi(s6) << endl;
    cout << s7 << ": " << s.atoi(s7) << "ref: " << atoi(s7) << endl;
    
    system("pause");
    return 0;
}