#include <vector>

using namespace std;

class Solution {
public:
    int maxDivScore(vector<int>& nums, vector<int>& divisors) {
        int ans = INT32_MAX, count = -1;
        for (auto divisor : divisors) {
            int temp = 0;
            for (auto num : nums) {
                if (num % divisor == 0)
                    temp++;
            }
            if (temp > count || (temp == count && divisor < ans)) {
                ans = divisor;
                count = temp;
            }
        }
        return ans;
    }
};