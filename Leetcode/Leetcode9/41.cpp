#include <vector>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            int temp = nums[i];
            while (temp > 0 && temp <= nums.size() && nums[temp - 1] != temp) {
                swap(temp, nums[temp - 1]);
            }
        }
        for (int i = 0; i < nums.size(); i++) {
            if (i + 1 != nums[i]) return i + 1;
        }
        return nums.size() + 1;
    }
};