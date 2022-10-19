#include <vector>
#include <stack>

using namespace std;


// Out of time.
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ans = INT32_MIN;
        for (int i = 0; i < heights.size(); i++) {
            int w = 0, h = INT32_MAX;
            for (int j = i; j >= 0; j--) {
                w++;
                h = min(heights[j], h);
                if (h * (i + 1) <= ans)
                    break;
                ans = max(ans, w * h);
            }
        }
        return ans;
    }
};

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n), right(n);

        stack<int> mono_stack;
        for (int i = 0; i < n; i++) {
            while (!mono_stack.empty() && heights[mono_stack.top()] >= heights[i])
                mono_stack.pop();
            left[i] = (mono_stack.empty() ? -1 : mono_stack.top());
            mono_stack.push(i);
        }

        mono_stack = stack<int>();
        for (int i = n - 1; i >= 0; i--) {
            while (!mono_stack.empty() && heights[mono_stack.top()] >= heights[i])
                mono_stack.pop();
            right[i] = (mono_stack.empty() ? n : mono_stack.top());
            mono_stack.push(i);
        }

        int ans = 0;
        for (int i = 0; i < n; i++)
            ans = max(ans, (right[i] - left[i] - 1) * heights[i]);
        return ans;
    }
};