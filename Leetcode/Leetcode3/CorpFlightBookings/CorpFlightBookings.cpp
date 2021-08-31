#include <vector>

using namespace std;

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> v(n, 0);
        for (auto& booking : bookings)
            for (int i = booking[0]; i <= n && i <= booking[1]; i++)
                v[i] += booking[2];
        return v;
    }
};