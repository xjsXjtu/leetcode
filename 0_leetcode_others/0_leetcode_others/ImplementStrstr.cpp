class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size() == 0)
            return 0;
        int hsize = haystack.size(), nsize = needle.size();
        for(int j=0; j<hsize-nsize+1; j++)
        {
            if(needle.compare(0, nsize, haystack, j, nsize) == 0)
            {
                return j;
            }
        }
        return -1;
    }
};