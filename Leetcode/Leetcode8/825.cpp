#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        vector<int> v(120, 0);
        for (auto age : ages) {
            v[age - 1]++;
        }

        for (int i = 1; i < v.size(); i++) {
            v[i] += v[i - 1];
        }

        int ans = 0;
        for (auto age : ages) {
            if (age <= 14) continue;
            ans += (v[age - 1] - v[0.5 * age + 7 - 1]) - 1;
        }
        return ans;
    }
};