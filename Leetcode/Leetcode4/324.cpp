#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> nums2 = nums;
        sort(nums2.begin(), nums2.end(), greater<int>());
        int cur = 0;
        for (int i = 1; i < nums.size(); i++) {
            nums[i] = nums2[cur];
            i++;
            cur++;
        }
        for (int i = 0; i < nums.size(); i++) {
            nums[i] = nums2[cur];
            i++;
            cur++;
        }
    }
};