#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int sum1 = 0, sum2 = 0;
        for (auto num : nums1)
            sum1 += num;
        for (auto num : nums2)
            sum2 += num;
        vector<int> n1, n2;
        int minus;
        if (sum1 > sum2) { 
            n1 = nums1;
            n2 = nums2;
            minus = sum1 - sum2;
        } else {
            n1 = nums2;
            n2 = nums1;
            minus = sum2 - sum1;
        }
        int ans = 0, i = n1.size() - 1, j = 0;
        while (minus > 0) {
            if (i < 0 && j >= n2.size()) return -1;
            if (j >= n2.size() || (n1[i] - 1 > 6 - n2[j])) {
                minus -= (n1[i] - 1);
                i--;
            } else if (i < 0 || (n1[i] - 1 <= 6 - n2[j])) {
                minus -= (6 - n2[j]);
                j++;
            }
            ans++;
        }
        return ans;
    }
};