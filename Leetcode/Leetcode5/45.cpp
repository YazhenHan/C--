#include <vector>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int ans = 0, maxPos = 0, end = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (i <= maxPos) {
                maxPos = max(maxPos, i + nums[i]);
                if (i == end) {
                    end = maxPos;
                    ans++;
                }
            }
        }
        return ans;
    }
};