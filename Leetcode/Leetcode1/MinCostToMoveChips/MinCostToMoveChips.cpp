#include <vector>

using namespace std;

class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int res1 = 0;
        int res2 = 0;
        for (auto i : position)
            if (i % 2 == 0)
                res2++;
            else
                res1++;
        return min(res1, res2);
    }
};