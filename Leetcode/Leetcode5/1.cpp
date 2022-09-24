#include <vector>

using namespace std;

class Solution {
public:
    int temperatureTrend(vector<int>& temperatureA, vector<int>& temperatureB) {
        int ans = 0, temp = 0;
        for (int i = 0; i < temperatureA.size() - 1; i++) {
            if (temperatureA[i + 1] > temperatureA[i] && temperatureB[i + 1] > temperatureB[i] ||
                temperatureA[i + 1] == temperatureA[i] && temperatureB[i + 1] == temperatureB[i] ||
                temperatureA[i + 1] < temperatureA[i] && temperatureB[i + 1] < temperatureB[i]) {
                    temp++;
                } else {
                    temp = 0;
                }
            ans = max(ans, temp);
        }
        return ans;
    }
};