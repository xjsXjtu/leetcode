class Solution {
public:
    string convertToTitle(int n) {
        int remainder = 0;
        string out;
        while(n)
        {
            remainder = (n - 1) % 26;
            n = (n - 1) / 26;
            out.push_back(remainder + 'A');
        }
        std::reverse(out.begin(), out.end());
        return out;
    }
};