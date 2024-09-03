#include <vector>

using namespace std;

class Solution {
public:
    long long maxStrength(vector<int>& nums) {
        long long temp = 1;
        int a = INT32_MIN, c0 = 0;
        for (auto num : nums) {
            if (num == 0) {
                c0++;
                continue;
            }
            temp *= num;
            if (num < 0) a = max(a, num);
        }
        if (temp > 0 && nums.size() - c0 > 0) return temp;
        if (nums.size() - c0 == 1) return c0 == 0 ? temp : 0;
        return temp / a;
    }
};