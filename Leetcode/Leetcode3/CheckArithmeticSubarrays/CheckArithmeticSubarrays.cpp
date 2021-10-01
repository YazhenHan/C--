#include <vector>

using namespace std;

class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> ans(l.size());
        for (int i = 0; i < l.size(); i++) {
            vector<int> temp(nums.begin() + l[i], nums.begin() + r[i]);
            sort(temp.begin(), temp.end());
            bool t = true;
            for (int j = 1; j < temp.size(); j++)
                if (temp[j] - temp[j - 1] != temp[1] - temp[0])
                    t = false;
            ans[i] = t;
        }
        return ans;
    }
};