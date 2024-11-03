#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> um;
        um[0]++;
        int ans = 0, temp = 0;
        for (int i = 0; i < nums.size(); i++) {
            temp += nums[i];
            if (um.count(temp - k)) ans += um[temp - k];
            um[temp]++;
        }
        return ans;
    }
};