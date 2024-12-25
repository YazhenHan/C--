#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        int hor = 0, ver = 0;
        sort(horizontalCut.begin(), horizontalCut.end(), greater<int>());
        sort(verticalCut.begin(), verticalCut.end(), greater<int>());
        int ans = 0;
        while (hor < horizontalCut.size() && ver < verticalCut.size()) {
            if (horizontalCut[hor] > verticalCut[ver]) {
                ans += horizontalCut[hor] * (ver + 1);
                hor++;
            }
            else {
                ans += verticalCut[ver] * (hor + 1);
                ver++;
            }
        }
        while (hor < horizontalCut.size()) {
            ans += horizontalCut[hor] * (ver + 1);
            hor++;
        }
        while (ver < verticalCut.size()) {
            ans += verticalCut[ver] * (hor + 1);
            ver++;
        }
        return ans;
    }
};