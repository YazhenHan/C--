#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), [](const auto & boxType1, const auto & boxType2) { return boxType1[1] > boxType2[1]; });
        int ans = 0;
        for (int i = 0; i < boxTypes.size(); i++) {
            ans += min(boxTypes[i][0], truckSize) * boxTypes[i][1];
            truckSize -= min(boxTypes[i][0], truckSize);
            if (truckSize == 0) break;
        }
        return ans;
    }
};