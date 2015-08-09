class Solution {
public:
    bool isPalindrome(string s) {
        if(s.size() == 0)
            return true;
        int i=0, j=s.size()-1;
        while(i<=j)
        {
            if(s[i] < '0' || (s[i] > '9' && s[i] < 'A') || (s[i] > 'Z' && s[i] < 'a') || s[i] > 'z' )
            {
                i++; continue;
            }
            if(s[j] < '0' || (s[j] > '9' && s[j] < 'A') || (s[j] > 'Z' && s[j] < 'a') || s[j] > 'z' )
            {
                j--; continue;
            }
            if(s[i] == s[j] || abs(s[i] - s[j]) == 'a' - 'A')
            {
                i++; j--;
            }
            else
                return false;
        }
        return true;
    }
};