#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
private:
    unordered_map<int, int> um;
    unordered_set<int> us;

    int dp(int day, vector<int> & costs) {
        if (day > 365) return 0;
        if (um.count(day)) return um[day];
        int ans = -1;
        if (us.count(day))
            ans = min(costs[0] + dp(day + 1, costs), min(costs[1] + dp(day + 7, costs), costs[2] + dp(day + 30, costs)));
        else
            ans = dp(day + 1, costs);
        um[day] = ans;
        return ans;
    }
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        for (auto day : days) us.insert(day);
        return dp(1, costs);
    }
};