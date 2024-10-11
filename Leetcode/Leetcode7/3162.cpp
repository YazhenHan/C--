#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        long long ans = 0;
        unordered_map<int, int> um;
        for (int i = 0; i < nums1.size(); i++) {
            if (um.count(nums1[i])) {
                ans += um[nums1[i]];
                continue;
            }
            int temp = 0;
            for (int j = 0; j < nums2.size(); j++) {
                if (nums1[i] % (nums2[j] * k) == 0) 
                    temp++;
            }
            um[nums1[i]] = temp;
        }
        return ans;
    }
};