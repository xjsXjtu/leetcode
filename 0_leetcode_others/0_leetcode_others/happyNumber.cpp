#include <vector>
#include <string>
#include <iostream>
#include <unordered_set>

class Solution {
private:
    int digitsSquareSum(int n)
    {
        int sum = 0;
        while (n)
        {
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        return sum;
    }
public:
    bool isHappy(int n) {
        std::unordered_set<int> us;
        while (n != 1)
        {
            n = digitsSquareSum(n);
            if (us.find(n) == us.end())
            {
                us.insert(n);
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution s;
    std::cout << s.isHappy(1) << std::endl;
    std::cout << s.isHappy(2) << std::endl;
    std::cout << s.isHappy(19) << std::endl;
    std::cout << s.isHappy(999) << std::endl;
    system("pause");
    return 0;
}