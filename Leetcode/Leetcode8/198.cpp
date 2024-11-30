#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int temp1 = 0, temp2 = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            int temp = max(temp2, temp1 + nums[i]);
            temp1 = temp2;
            temp2 = temp;
        }
        return temp2;
    }
};