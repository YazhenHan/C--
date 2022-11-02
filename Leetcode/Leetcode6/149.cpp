#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
private:
    int gcd(int x, int y) {
        return y ? gcd(y, x % y) : x;
    }
public:
    int maxPoints(vector<vector<int>>& points) {
        int ans = 0;
        sort(points.begin(), points.end());
        for (int i = 0; i < points.size(); i++) {
            unordered_map<string, int> um;
            for (int j = i + 1; j < points.size(); j++) {
                int xm = points[j][0] - points[i][0], ym = points[j][1] - points[i][1];
                if (xm == 0) {
                    um["0%"]++;
                } else if (ym == 0) {
                    um["%0"]++;
                } else {
                    int g = gcd(xm, ym);
                    xm /= g;
                    ym /= g;
                    um[to_string(xm) + "%" + to_string(ym)]++;
                }
            }
            for (const auto & t : um)
                ans = max(ans, t.second);
            if (ans + 1 > points.size() / 2)
                break;
        }
        return ans + 1;
    }
};