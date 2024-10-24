#include <vector>

using namespace std;

class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        vector<int> v(24, 0);
        long long ans = 0;
        for (const auto & hour : hours) {
            ans += v[(24 - hour % 24) % 24];
            v[hour % 24]++;
        }
        return ans;
    }
};