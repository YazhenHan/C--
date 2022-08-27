#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> dp1(nums.size(), -1);
        vector<int> dp2(nums.size(), 1);
        int t1 = 1, t2 = 0;
        for (int i = 0; i < nums.size(); i++) {
            int t3 = 0, t4 = -1;
            for (int j = i - 1; j >= 0; j--) {
                if (nums[i] % nums[j] == 0 && dp2[j] > t3) {
                    t3 = dp2[j];
                    t4 = j;
                }
            }
            if (t4 != -1) {
                dp1[i] = t4;
                dp2[i] = dp2[t4] + 1;
                if (dp2[i] > t1) {
                    t1 = dp2[i];
                    t2 = i;
                }
            }
        }
        vector<int> ans;
        while (t2 != -1) {
            ans.push_back(nums[t2]);
            t2 = dp1[t2];
        }
        return ans;
    }
};