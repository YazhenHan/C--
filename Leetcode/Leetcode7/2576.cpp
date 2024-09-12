#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int m = n / 2;
        int ans = 0;
        for (int i = 0, j = m; i < m && j < n; i++) {
            while (j < n && 2 * nums[i] > nums[j]) j++;
            if (j < n) {
                ans += 2;
                j++;
            }
        }
        return ans;
    }
};