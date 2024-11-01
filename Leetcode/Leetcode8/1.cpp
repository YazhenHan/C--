#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map<int, int> um;
        for (int i = 0; i < nums.size(); i++) {
            um[nums[i]] = i;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (um.count(target - nums[i]) && um[target - nums[i]] != i) {
                return {i, um[target - nums[i]]};
            }
        }
        return {};
    }
};