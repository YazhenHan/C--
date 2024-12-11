#include <vector>

using namespace std;

class Solution {
public:
    int semiOrderedPermutation(vector<int>& nums) {
        int c1, cn;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) c1 = i;
            if (nums[i] == nums.size()) cn = i;
        }
        if (c1 > cn) return c1 + (nums.size() - cn - 1) - 1;
        else return c1 + (nums.size() - cn - 1);
    }
};