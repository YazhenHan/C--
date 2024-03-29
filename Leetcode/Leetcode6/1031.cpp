#include <vector>
#include <numeric>

using namespace std;

class Solution {
private:
    int help(const vector<int> & nums, int firstLen, int secondLen) {
        int suml = accumulate(nums.begin(), nums.begin() + firstLen, 0);
        int maxSumL = suml;
        int sumr = accumulate(nums.begin() + firstLen, nums.begin() + firstLen + secondLen, 0);
        int ans = maxSumL + sumr;
        for (int i = firstLen + secondLen, j = firstLen; i < nums.size(); i++, j++) {
            suml += nums[j] - nums[j - firstLen];
            maxSumL = max(maxSumL, suml);
            sumr += nums[i] - nums[i - secondLen];
            ans = max(ans, maxSumL + sumr);
        }
        return ans;
    }
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        return max(help(nums, firstLen, secondLen), help(nums, secondLen, firstLen));
    }
};