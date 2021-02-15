#include <vector>

using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0, temp = 0;
        for (auto num : nums)
        {
            if (num == 1)
                temp++;
            else
                temp = 0;
            ans = max(ans, temp);
        }
        return ans;
    }
};