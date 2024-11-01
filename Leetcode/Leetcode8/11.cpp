#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int ans = (right - left) * min(height[left], height[right]);
        while (left < right) {
            if (height[left] >= height[right]) {
                right--;
            } else {
                left++;
            }
            ans = max(ans, (right - left) * min(height[left], height[right]));
        }
        return ans;
    }
};