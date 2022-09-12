#include <vector>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> leftHeight(height.size()), rightHeight(height.size());
        int tempHeight = 0;
        for (int i = 0; i < height.size(); i++) {
            tempHeight = max(tempHeight, height[i]);
            leftHeight[i] = tempHeight;
        }
        tempHeight = 0;
        for (int i = height.size() - 1; i >= 0; i--) {
            tempHeight = max(tempHeight, height[i]);
            rightHeight[i] = tempHeight;
        }
        int ans = 0;
        for (int i = 0; i < height.size(); i++)
            ans += min(leftHeight[i], rightHeight[i]) - height[i];
        return ans;
    }
};