#include <vector>

using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        bool res = true;
        int change5 = 0;
        int change10 = 0;
        int change20 = 0;
        for (auto bill : bills)
        {
            switch (bill)
            {
            case 5:
                change5++;
                break;
            case 10:
                if (change5 == 0)
                {
                    return false;
                }
                change5--;
                change10++;
                break;
            case 20:
                if (change5 == 0)
                {
                    return false;
                }
                if (change10 > 0)
                {
                    change10--;
                    change5--;
                    change20++;
                    break;
                }
                if (change5 < 3)
                {
                    return false;
                }
                change5 -= 3;
                change20++;
                break;
            default:
                break;
            }
        }
        return true;
    }
};