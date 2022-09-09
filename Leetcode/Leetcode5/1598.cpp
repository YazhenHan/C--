#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int minOperations(vector<string>& logs) {
        int ans = 0;
        for (int i = 0; i < logs.size(); i++) {
            if (logs[i][0] == '.' && logs[i][1] == '.') {
                ans = max(0, ans - 1);
                continue;
            }
            if (logs[i][0] == '.' && logs[i][1] == '/')
                continue;
            ans++;
        }
        return ans;
    }
};