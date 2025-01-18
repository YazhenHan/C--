#include <vector>

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int ans = 0;
        for (int num : nums) {
            if (num < k) ans++;
        }
        return ans;
    }
};