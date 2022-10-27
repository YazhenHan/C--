#include <vector>

using namespace std;

class Solution {
public:
    int arraySign(vector<int>& nums) {
        int t = 0;
        for (auto num : nums)
            if (num < 0)
                t++;
            else if (num == 0)
                return 0;
        if (t % 2 == 0)
            return 1;
        return -1;
    }
};