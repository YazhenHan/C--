#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_set<int> us;
        long long sum = 0, ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (us.size() >= k) {
                us.erase(nums[i - k]);
                sum -= nums[i - k];
            }
            for (int j = max(i - k + 1, 0); us.count(nums[i]); j++) {
                us.erase(nums[j]);
                sum -= nums[j];                    
            }
            us.insert(nums[i]);
            sum += nums[i];
            if (us.size() == k)
                ans = max(ans, sum);
        }
        return ans;
    }
};