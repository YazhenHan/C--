#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom, vector<int>& moveTo) {
        unordered_set<int> us(nums.begin(), nums.end());
        for (int i = 0; i < moveFrom.size(); i++) {
            us.erase(moveFrom[i]);
            us.insert(moveTo[i]);
        }
        vector<int> ans(us.begin(), us.end());
        sort(ans.begin(), ans.end());
        return ans;
    }
};