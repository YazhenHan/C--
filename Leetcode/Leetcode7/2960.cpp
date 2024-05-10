#include <vector>

using namespace std;

class Solution {
public:
    int countTestedDevices(vector<int>& batteryPercentages) {
        int ans = 0;
        for (int i = 0; i < batteryPercentages.size(); i++) {
            if (batteryPercentages[i] == 0)
                continue;
            for (int j = i + 1; j < batteryPercentages.size(); j++) {
                batteryPercentages[j] = max(0, batteryPercentages[j] - 1);
            }
            ans++;
        }
        return ans;
    }
};