#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> um;
        int temp = 0, ans = 0;
        um[0]++;
        for (int i = 0; i < nums.size(); i++) {
            temp += nums[i];
            um[temp]++;
            if (um.count(temp - k)) {
                if (k == 0)
                    ans += um[temp - k] - 1;
                else
                    ans += um[temp - k];
            }
        }
        return ans;
    }
};