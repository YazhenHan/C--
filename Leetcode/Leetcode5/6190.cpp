#include <vector>

using namespace std;

class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
        if (k == 1) {
            vector<int> ans;
            for (int i = 1; i < nums.size() - 1; i++) ans.push_back(i);
            return ans;
        }
        vector<bool> left(nums.size());
        int l = -1;
        for (int i = 1; i < k; i++)
            if (nums[i] > nums[i - 1])
                l = i - 1;
        for (int i = k; i < nums.size() - k; i++) {
            int ti = i - 1;
            if (nums[ti] <= nums[ti - 1] && ti - l >= k)
                left[i] = true;
            else {
                left[i] = false;
                if (nums[ti] > nums[ti - 1])
                    l = ti - 1;
            }
        }

        vector<bool> right(nums.size());
        int r = nums.size();
        for (int i = nums.size() - 2; i > nums.size() - k - 1; i--)
            if (nums[i] > nums[i + 1])
                r = i + 1;
        for (int i = nums.size() - k - 1; i >= k; i--) {
            int ti = i + 1;
            if (nums[ti] <= nums[ti + 1] && r - ti >= k)
                right[i] = true;
            else {
                right[i] = false;
                if (nums[ti] > nums[ti + 1])
                    r = ti + 1;
            }
        }

        vector<int> ans;
        for (int i = k; i < nums.size() - k; i++)
            if (left[i] && right[i])
                ans.push_back(i);
        return ans;
    }
};