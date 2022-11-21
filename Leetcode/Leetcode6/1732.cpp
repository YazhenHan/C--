#include <vector>

using namespace std;

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans = 0, t = 0;
        for (const auto & g : gain) {
            t += g;
            ans = max(ans, t);
        }
        return ans;
    }
};