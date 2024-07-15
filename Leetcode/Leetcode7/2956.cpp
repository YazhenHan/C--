#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> us1(nums1.begin(), nums1.end());
        unordered_set<int> us2(nums2.begin(), nums2.end());
        vector<int> ans(2, 0);
        for (auto num : nums1) {
            if (us2.count(num)) ans[0]++;
        }
        for (auto num : nums2) {
            if (us1.count(num)) ans[1]++;
        }
        return ans;
    }
};