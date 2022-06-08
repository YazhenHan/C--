#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] > ans.back().back()) ans.push_back(intervals[i]);
            if (intervals[i][1] > ans.back().back()) ans.back().back() = intervals[i][1];
        }
        return ans;
    }
};