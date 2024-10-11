#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        long long ans = 0;
        int maxNum = INT32_MIN;
        unordered_map<int, int> um1;
        unordered_map<int, int> um2;
        for (auto num : nums1) {
            um1[num]++;
            maxNum = max(num, maxNum);
        }
        for (auto num : nums2) {
            um2[num]++;
        }
        for (auto & pair : um2) {
            for (int a = pair.first * k; a <= maxNum; a += pair.first * k) {
                ans += 1L * um1[a] * pair.second;
            }
        }
        return ans;
    }
};