#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_set<int> us;
        int ans = -1;
        for (auto num : nums) {
            if (us.count(-num))
                ans = max(ans, abs(num));
            us.insert(num);
        }
        return ans;
    }
};