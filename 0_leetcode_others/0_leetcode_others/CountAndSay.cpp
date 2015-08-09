class Solution {
public:
    string countAndSay(int n) {
        assert(n>=1);
        if(n==1)
            return "1";
        string in="11", out;
        for(int c=1; c<n-1; c++)
        {
            int i=0, j=1;
            for(; j<in.size(); j++)
            {
                if(in[j] != in[i])
                {
                    out.push_back('0' + j - i);
                    out.push_back(in[i]);
                    i = j;
                }
            }
            out.push_back('0' + j - i);
            out.push_back(in[i]);
            in = out;
            out = "";
        }
        return in;
    }
};