#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> left(heights.size()), right(heights.size());
        stack<int> stLeft, stRight;
        for (int i = 0; i < heights.size(); i++) {
            while (!stLeft.empty() && heights[stLeft.top()] >= heights[i]) stLeft.pop();
            left[i] = stLeft.empty() ? -1 : stLeft.top();
            stLeft.push(i);
        }
        for (int i = heights.size() - 1; i >= 0; i--) {
            while (!stRight.empty() && heights[stRight.top()] >= heights[i]) stRight.pop();
            right[i] = stRight.empty() ? heights.size() : stRight.top();
            stRight.push(i);
        }

        int ans = 0;
        for (int i = 0; i < heights.size(); i++) {
            ans = max(ans, (right[i] - left[i] - 1) * heights[i]);
        }
        return ans;
    }
};