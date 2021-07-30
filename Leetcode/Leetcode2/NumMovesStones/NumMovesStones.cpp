#include <vector>

using namespace std;

class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        int right = max(max(a, b), c);
        int left = min(min(a, b), c);
        int middle = a + b + c - right - left;
        int ma = right - left - 2;
        int mi;
        if (middle - left == 2 || right - middle == 2)
            mi = 1;
        else
            mi = min(ma, min(middle - left, min(right - middle, 2)));
        vector<int> ans = {mi, ma};
        return ans;
    }
};