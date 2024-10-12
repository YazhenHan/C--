#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        int ans = 0;
        unordered_set<int> us;
        for (auto num : nums) {
            if (us.count(num)) {
                ans = ans ^ num;
            }
            us.insert(num);
        }
        return ans;
    }
};