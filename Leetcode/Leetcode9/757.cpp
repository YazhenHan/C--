#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int> & interval1, const vector<int> & interval2) {
            if (interval1[0] == interval2[0]) return interval1[1] >= interval2[1];
            return interval1[0] < interval2[0];
        });
        int ans = 2, temp1 = intervals.back()[0], temp2 = temp1 + 1;
        for (int i = intervals.size() - 2; i >= 0; i--) {
            if (!(temp1 >= intervals[i][0] && temp1 <= intervals[i][1])) {
                temp1 = intervals[i][0];
                temp2 = temp1 + 1;
                ans += 2;
            } else {
                if (!(temp2 >= intervals[i][0] && temp2 <= intervals[i][1])) {
                    temp2 = temp1;
                    temp1 = intervals[i][0];
                    ans++;
                }
            }
        }
        return ans;
    }
};