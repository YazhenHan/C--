#include <vector>

using namespace std;

class Solution {
public:
    vector<int> bestCoordinate(vector<vector<int>>& towers, int radius) {
        int ma = 0;
        vector<int> ans = {0, 0};
        for (int x = 0; x <= 50; x++) {
            for (int y = 0; y <= 50; y++) {
                int temp = 0;
                for (const auto tower : towers) {
                    int distance2 = (tower[0] - x) * (tower[0] - x) + (tower[1] - y) * (tower[1] - y);
                    if (distance2 <= radius * radius)
                        temp += floor(tower[2] / (1 + sqrt(distance2)));
                }
                if (temp > ma) {
                    ans = {x, y};
                    ma = temp;
                }
            }
        }
        return ans;
    }
};