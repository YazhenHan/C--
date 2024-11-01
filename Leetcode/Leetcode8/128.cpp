#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> um;
        int ans = 0;
        for (auto num : nums) {
            if (um.count(num)) continue;
            int left = 0, right = 0;
            if (um.count(num - 1)) left = um[num - 1];
            if (um.count(num + 1)) right = um[num + 1];
            um[num] = 1 + left + right;
            um[num - left] = um[num];
            um[num + right] = um[num];
            ans = max(ans, um[num]);
        }
        return ans;
    }
};