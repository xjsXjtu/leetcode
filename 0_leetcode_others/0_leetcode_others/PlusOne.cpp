#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int bits = digits.size();
        int carry_bit    = (digits[bits - 1] + 1) / 10;
        digits[bits - 1] = (digits[bits - 1] + 1) % 10;
        
        for(int b = bits - 2; b >= 0 && carry_bit > 0; b--)
        {
            carry_bit = (digits[b] + 1) / 10;
            digits[b] = (digits[b] + 1) % 10;
        }

        if(carry_bit)
        {
            digits.emplace(digits.begin(), 1);
        }
        return digits;
    }
};
}