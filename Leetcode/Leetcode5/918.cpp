#include <vector>

using namespace std;

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int sum = nums[0], tempMax = nums[0], ansMax = nums[0], tempMin = nums[0], ansMin = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            tempMax = max(tempMax + nums[i], nums[i]);
            ansMax = max(ansMax, tempMax);
            tempMin = min(tempMin + nums[i], nums[i]);
            ansMin = min(ansMin, tempMin);
            sum += nums[i];
        }
        if (sum == ansMin) return ansMax;
        return max(ansMax, sum - ansMin);
    }
};