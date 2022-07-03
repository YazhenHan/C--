#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int nextGreaterElement(int n) {
        vector<int> nums;
        while (n != 0) {
            nums.push_back(n % 10);
            n = n / 10;
        }
        reverse(nums.begin(), nums.end());
        int i = nums.size() - 2;
        for (; i >= 0; i--)
            if (nums[i] < nums[i + 1])
                break;
        if (i != -1) {
            int j = nums.size() - 1;
            for (; j >= 0; j--)
                if (nums[i] < nums[j])
                    break;
            swap(nums[i], nums[j]);
            int l = i + 1, r = nums.size() - 1;
            while (l <= r) {
                swap(nums[l], nums[r]);
                l++;
                r--;
            }
            long ans = 0;
            for (auto num : nums)
                ans = ans * 10 + num;
            return ans > INT32_MAX ? -1 : ans;
        }
        return -1;
    }
};