#include <vector>

using namespace std;

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> v(n, 0);
        for (auto& booking : bookings) {
            v[booking[0] - 1] += booking[2];
            if (booking[1] < n)
                v[booking[1]] -= booking[2];
        }
        for (int i = 1; i < n; i++)
            v[i] = v[i - 1] + v[i];
        return v;
    }
};