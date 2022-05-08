#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> flags(nums.size(), 0);
        for (auto num : nums)
            flags[num - 1]++;
        vector<int> ans;
        for (int i = 0; i <  flags.size(); i++)
            if(flags[i] == 2)
                ans.push_back(i + 1);
        return ans;
    }
};