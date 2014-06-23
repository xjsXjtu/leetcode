#include <string>
#include <iostream>
#include <assert.h>
using namespace std;

class Solution {
public:
#if 1
    bool isMatch(const char *s, const char *p)
    {
        string sstr(s), dstr(p);
        int srci = 0, desi;
        for(srci=0; srci<sstr.size();)
        {
            if(dstr[desi] == '.' && dstr[desi + 1] != '*') // [.]x
            {
                srci++;
                desi++;
            }
            else if(dstr[desi] == '.' && dstr[desi + 1] == '*') // [.*]
            {
                srci = sstr.size() - 1;
                desi += 2;
            }
            else if(dstr[desi] != '*' && dstr[desi + 1] == '*') // [x*]
            {
                for(; sstr[srci] == dstr[desi]; srci++);
                desi += 2;
            }
            else // [abc]d*, [abc].*
            {
                int unit_len = 1;
                for(; dstr[desi + unit_len] !='.' && dstr[desi + unit_len] != '*'; )
                {
                    unit_len++;
                    if()
                }
            }
        }
        if(srci == dstr.size())
            return true;
        return false;
    }
#else
    bool isMatch(const char *s, const char *p) 
    {
          assert(s && p);
          if (*p == '\0') return *s == '\0';
 
          // next char is not '*': must match current character
          if (*(p+1) != '*') {
            assert(*p != '*');
            return ((*p == *s) || (*p == '.' && *s != '\0')) && isMatch(s+1, p+1);
          }
          // next char is '*'
          while ((*p == *s) || (*p == '.' && *s != '\0')) {
            if (isMatch(s, p+2)) return true;
            s++;
          }
          return isMatch(s, p+2);
        }
#endif
};

int main()
{
    typedef struct test_s{
        char *src;
        char *reg;
    }Test;

    Test test[] = {
        {"aa", "a"},
        {"aa", "aa"},
        {"aaa", "aa"},
        {"aa", "a*"},
        {"aa", ".*"},
        {"aab", "c*a*b*"},

        {"acab", ".*ab.*"}, // true
        {"abac", ".*ab.*"}  // true
    };

    Solution s;
    for(int i=0; i<sizeof(test)/sizeof(Test); i++)
    {
        cout << "isMatch(" << test[i].src << ", " << test[i].reg << ") -> " << s.isMatch(test[i].src, test[i].reg) << endl;
    }

    system("pause");
    return 0;
}