#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        ans.emplace_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++) {
            vector<int> temp = ans.back();
            if (temp[1] >= intervals[i][0]) {
                ans[ans.size() - 1][1] = max(ans[ans.size() - 1][1], intervals[i][1]);
            } else {
                ans.emplace_back(intervals[i]);
            }
        }
        return ans;
    }
};