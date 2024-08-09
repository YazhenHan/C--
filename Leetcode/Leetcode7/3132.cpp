#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minimumAddedInteger(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        for (int i : {2, 1, 0}) {
            int left = i, right = 0;
            while (left < nums1.size() && right < nums2.size()) {
                if (nums2[right] - nums1[left] == nums2[0] - nums1[i]) {
                    right++;
                }
                left++;
                if (left - right > 2) break;
            }
            if (right == nums2.size())
                return nums2[0] - nums1[i];
        }
        return 0;
    }
};