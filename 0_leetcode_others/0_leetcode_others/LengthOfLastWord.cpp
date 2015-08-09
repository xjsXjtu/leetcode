class Solution {
public:
    int lengthOfLastWord(string s) {
        if(s.size() == 0)
            return 0;
        int i=0, j=0, size = s.size();
        while(s[i] == ' ')i++;
        while(s[size-1] == ' ') size--;
        for(j=i; j<size; j++)
        {
            if(s[j] == ' ')
            {
                i = j + 1;
            }
        }
        return j - i;
    }
};