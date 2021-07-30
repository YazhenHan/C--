#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> heights2 = heights;
        sort(heights2.begin(), heights2.end());
        int ans = 0;
        for (size_t i = 0; i < heights.size(); i++)
            if (heights[i] != heights2[i])
                ans++;
        return ans;
    }
};