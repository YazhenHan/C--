#include <vector>

using namespace std;

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int ans = 0, vi = values.front();
        for (int j = 1; j < values.size(); j++) {
            int temp = vi + values[j] - j;
            vi = max(vi, values[j] + j);
            ans = max(ans, temp);
        }
        return ans;
    }
};