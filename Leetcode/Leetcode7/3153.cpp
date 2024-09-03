#include <vector>

using namespace std;

class Solution {
public:
    long long sumDigitDifferences(vector<int>& nums) {
        long long ans = 0;
        while (true) {
            vector<int> v(10, 0);
            bool flag = true;
            for (auto & num : nums) {
                v[num % 10]++;
                num /= 10;
                if (num != 0) flag = false;
            }
            int temp = nums.size();
            for (auto t : v) {
                ans += (long long)t * (long long)(temp - t);
                temp -= t;
            }
            if (flag) break;
        }
        return ans;
    }
};