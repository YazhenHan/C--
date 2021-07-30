#include <algorithm>

class Solution {
public:
    int binaryGap(int n) {
        int ans = 0;
        int left = INT32_MIN;
        for (int i = 0; n != 0; i++)
        {
            if (n % 2 == 1)
            {
                if (left == INT32_MIN)
                {
                    left = i;
                    continue;
                }
                if (i - left > ans)
                {
                    ans = i - left;
                }
                left = i;
            }
            n = n / 2;
        }
        return ans;
    }
};