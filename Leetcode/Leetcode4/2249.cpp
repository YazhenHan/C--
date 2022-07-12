#include <vector>
#include <set>
#include <utility>

using namespace std;

class Solution {
public:
    int countLatticePoints(vector<vector<int>>& circles) {
        set<pair<int, int>> sp;
        int left = INT32_MAX, right = INT32_MIN, bottom = INT32_MAX, top = INT32_MIN;
        for (auto& circle : circles) {
            int xi = circle[0], yi = circle[1], ri = circle[2];
            for (int x = xi - ri; x <= xi + ri; x++) {
                for (int y = yi - ri; y <= yi + ri; y++) {
                    if ((x - xi) * (x - xi) + (y - yi) * (y - yi) <= ri * ri) {
                        sp.insert({x, y});
                    }
                }
            }
        }
        return sp.size();
    }
};