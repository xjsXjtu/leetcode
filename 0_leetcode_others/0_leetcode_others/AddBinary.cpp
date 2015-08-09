class Solution {
public:
    string addBinary(string a, string b) {
        int asize = a.size(), bsize = b.size();
        int carry_bit = 0;
        string out;
        int ia = asize - 1, ib = bsize -1;
        while(ia >= 0 || ib >= 0 || carry_bit > 0 )
        {
            int av = ia < 0 ? 0 : a[ia] - '0';
            int bv = ib < 0 ? 0 : b[ib] - '0';
            out.push_back('0' + (av + bv + carry_bit) % 2);
            carry_bit = (av + bv + carry_bit) / 2;
            
            ia--; ib--;
        }
        reverse(out.begin(), out.end());
        return out;
    }
};