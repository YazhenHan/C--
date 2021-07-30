#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> selfDividingNumbers(int left, int right)
    {
        vector<int> res;
        for (int num = left; num <= right; num++)
        {
            if (isSelfDividingNumber(num))
            {
                res.push_back(num);
            }
        }
        return res;
    }

private:
    bool isSelfDividingNumber(int num)
    {
        int constNum = num;
        while (num != 0)
        {
            int temp = num % 10;
            if (temp == 0 || constNum % temp != 0)
            {
                return false;
            }
            num = num / 10;
        }
        return true;
    }
};

int main()
{
    return 0;
}