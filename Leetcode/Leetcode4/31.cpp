#include <vector>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
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
        }
        int l = i + 1, r = nums.size() - 1;
        while (l <= r) {
            swap(nums[l], nums[r]);
            l++;
            r--;
        }
    }
};