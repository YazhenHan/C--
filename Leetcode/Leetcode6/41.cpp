#include <vector>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            int temp = nums[i];
            while (temp > 0 && temp <= nums.size() && temp != nums[temp - 1]) {
                int t = nums[temp - 1];
                nums[temp - 1] = temp;
                temp = t;
            }
        }
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != i + 1)
                return i + 1;
        }
        return nums.size() + 1;
    }
};