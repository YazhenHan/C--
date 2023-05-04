#include <vector>

using namespace std;

class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
        int ans = logs[0][0], t = logs[0][1];
        for (int i = 1; i < logs.size(); i++) {
            if (logs[i][1] - logs[i - 1][1] > t || (logs[i][1] - logs[i - 1][1] == t && logs[i][0] < ans)) {
                t = logs[i][1] - logs[i - 1][1];
                ans = logs[i][0];
            }
        }
        return ans;
    }
};