#include <unordered_map>

using namespace std;

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int> um;
        int sum = 0, ans = 0;
        for (auto & num : nums) {
            um[sum]++;
            sum += num;
            ans += um[sum - goal];
        }
        return ans;
    }
};