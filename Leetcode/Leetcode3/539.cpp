#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
private:
    int getMin(string timePoint) {
        int left = (timePoint[0] - '0') * 10 + (timePoint[1] - '0');
        int right = (timePoint[3] - '0') * 10 + (timePoint[4] - '0');
        return left * 60 + right;
    }
public:
    int findMinDifference(vector<string>& timePoints) {
        if (timePoints.size() > 1440)
            return 0;
        vector<int> timePoints2;
        for (auto timePoint : timePoints)
            timePoints2.push_back(getMin(timePoint));
        sort(timePoints2.begin(), timePoints2.end());
        int ans = 1440;
        for (int i = 1; i < timePoints2.size(); i++)
            if (timePoints2[i] - timePoints2[i - 1] < ans)
                ans = timePoints2[i] - timePoints2[i - 1];
        if ((timePoints2[0] - timePoints2.back() + 1440) < ans)
            ans = timePoints2[0] - timePoints2.back() + 1440;
        return ans;
    }
};