class Solution {
public:
    int compareVersion(string version1, string version2) {
        int v1 = 0, v2 = 0;
        int i1=0, i2=0, s1=version1.size(), s2=version2.size();
        while(i1 < s1 || i2 < s2)
        {
            v1 = v2 = 0;
            while(version1[i1] != '.' && i1<s1)
            {
                v1 = v1 * 10 + version1[i1] - '0';
                i1++;
            }
            while(version2[i2] != '.' && i2<s2)
            {
                v2 = v2 * 10 + version2[i2] - '0';
                i2++;
            }
            i1++; i2++;
            if(v1 > v2) return 1;
            if(v1 < v2) return -1;
        }
        return 0;
    }
};