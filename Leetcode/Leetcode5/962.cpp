#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        vector<int> v(nums.size());
        for (int i = 0; i < nums.size(); i++)
            v[i] = i;
        stable_sort(v.begin(), v.end(), [nums](int i, int j)->bool {return nums[i] < nums[j];});
        int ans = 0, temp = v[0];
        for (int i = 1; i < v.size(); i++) {
            ans = max(ans, v[i] - temp);
            temp = min(temp, v[i]);
        }
        return ans;
    }
};