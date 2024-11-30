#include <vector>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        vector<int> v(2 * 10000 + 1, 0);
        for (int num : nums) {
            v[num + 10000]++;
        }
        for (int i = 20000; i >= 0; i--) {
            if (v[i] >= k)
                return i - 10000;
            k -= v[i];
        }
        return -10000;
    }
};