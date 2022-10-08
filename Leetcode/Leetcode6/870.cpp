#include <vector>
#include <algorithm>

using namespace std;

// Out of time.
class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans(nums1.size(), -1);
        sort(nums1.begin(), nums1.end());
        for (auto num : nums1) {
            int c = -1, c2 = -1, m = INT32_MIN;
            for (int i = 0; i < nums2.size(); i++) {
                if (num > nums2[i] && ans[i] == -1) {
                    if (c == -1)
                        c = i;
                    else if (nums2[i] >= nums2[c])
                        c = i;
                }
                if (nums2[i] >= m && ans[i] == -1) {
                    m = nums2[i];
                    c2 = i;
                }
            }
            if (c == -1) ans[c2] = num;
            else ans[c] = num;
        }
        return ans;
    }
};

#include <unordered_map>

class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans(nums1.size(), -1);
        unordered_multimap<int, int> umm;
        for (int i = 0; i < nums2.size(); i++)
            umm.insert({nums2[i], i});
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int i = 0, j = 0, k = nums2.size() - 1;
        while (i < nums1.size() && j <= k) {
            if (nums1[i] > nums2[j]) {
                for (auto pos = umm.equal_range(nums2[j]); pos.first != pos.second; ++pos.first) {
                    if (ans[pos.first->second] != -1)
                        continue;
                    ans[pos.first->second] = nums1[i];
                    break;
                }
                j++;
            } else {
                for (auto pos = umm.equal_range(nums2[k]); pos.first != pos.second; ++pos.first) {
                    if (ans[pos.first->second] != -1)
                        continue;
                    ans[pos.first->second] = nums1[i];
                    break;
                }
                k--;
            }
            i++;
        }
        return ans;
    }
};