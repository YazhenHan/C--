#include <vector>

using namespace std;

class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        int sum = 0;
        for (auto machine : machines)
            sum += machine;
        if (sum % machines.size() != 0) return -1;
        int avg = sum / machines.size();
        vector<int> a;
        for (auto machine : machines)
            a.push_back(machine - avg);
        int ans = 0, s = 0;
        for (auto t : a) {
            s += t;
            ans = max(ans, max(abs(s), t));
        }
        return ans;
    }
};