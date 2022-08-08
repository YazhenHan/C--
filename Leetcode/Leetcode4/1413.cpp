#include <vector>

using namespace std;

class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int cur = 0, curmin = INT32_MAX;
        for (auto & num : nums) {
            cur += num;
            curmin = min(curmin, cur);
        }
        return curmin < 0 ? abs(curmin) + 1 : 1;
    }
};