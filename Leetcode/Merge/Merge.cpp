#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    bool static cmp(vector<int> interval1, vector<int> interval2) {
        if (interval1[0] == interval2[0])
            return interval1[1] < interval2[1];
        return interval1[0] < interval2[0];
    }
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() == 0)
            return {};
        sort(intervals.begin(), intervals.end(), cmp);
        vector<vector<int>> res;
        res.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++)
        {
            auto left = res.back(), right = intervals[i];
            if (left[1] >= right[0])
            {
                res.pop_back();
                res.push_back({left[0], max(left[1], right[1])});
            }
            else
            {
                res.push_back(right);
            }
        }
        return res;
    }
};