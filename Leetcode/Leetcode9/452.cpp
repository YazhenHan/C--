#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int ans = 1, temp = points.back()[0];
        for (int i = points.size() - 2; i >= 0; i--) {
            if (points[i][1] >= temp) continue;
            temp = points[i][0];
            ans++;
        }
        return ans;
    }
};