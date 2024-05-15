#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long numberOfWeeks(vector<int>& milestones) {
        if (milestones.size() == 1) return 1;
        sort(milestones.begin(), milestones.end());
        vector<int> v(milestones.size(), 0);
        long long ans = 0;
        while (true) {
            long long t = ans;
            for (int i = 0; i < milestones.size(); i++) {
                int temp = min(ans + 1 - v[i] * 2, (long long)milestones[i]);
                ans += temp;
                v[i] += temp;
                milestones[i] -= temp;
            }
            if (t == ans)
                break;
        }
        return ans;
    }
};