#include <vector>

using namespace std;

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int ans = 1, temp1 = 1, temp2 = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1])
                temp1 = temp2 + 1;
            if (nums[i] < nums[i - 1])
                temp2 = temp1 + 1;
        }
        return max(temp1, temp2);
    }
};