#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        sort(tasks.begin(), tasks.end());
        int temp = 0, ans = 0;
        for (int i = 0; i < tasks.size(); i++) {
            if (i == 0 || tasks[i] == tasks[i - 1]) {
                temp++;
            } else {
                if (temp == 1) {
                    return -1;
                } else {
                    if (temp % 3 == 1) {
                        ans += (temp - 4) / 3 + 2;
                    } else if (temp % 3 == 2) {
                        ans += (temp - 2) / 3 + 1;
                    } else {
                        ans += temp / 3;
                    }
                }
                temp = 1;
            }
        }
        if (temp == 1) {
            return -1;
        } else {
            if (temp % 3 == 1) {
                ans += (temp - 4) / 3 + 2;
            } else if (temp % 3 == 2) {
                ans += (temp - 2) / 3 + 1;
            } else {
                ans += temp / 3;
            }
        }
        temp = 1;
        return ans;
    }
};