#include <vector>

using namespace std;

class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        int ans = INT32_MIN;
        for (int i = 0; i < manager.size(); i++) {
            int temp = 0, c = i;
            while (manager[c] != -1) {
                c = manager[c];
                temp += informTime[c];
            }
            ans = max(ans, temp);
        }
        return ans;
    }
};