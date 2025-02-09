#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int left = 0, right = 0;
        while (right < nums.size()) {
            int i = right;
            while (i < nums.size() && (i == right || nums[i] == nums[i - 1])) {
                i++;
            }
            for (int j = 0; j < min(2, i - right); j++) {
                nums[left] = nums[right];
                left++;
            }
            right = i;
        }
        return left;
    }
};