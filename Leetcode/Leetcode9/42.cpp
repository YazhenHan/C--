#include <vector>
#include <utility>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> lm = height, rm = height;
        
        for (int i = 1; i < height.size(); i++) {
            lm[i] = max(height[i], lm[i - 1]);
        }
        for (int i = height.size() - 2; i >= 0; i--) {
            rm[i] = max(height[i], rm[i + 1]);
        }

        int ans = 0;
        for (int i = 0; i < height.size(); i++) {
            ans += min(lm[i], rm[i]) - height[i];
        }
        return ans;
    }
};