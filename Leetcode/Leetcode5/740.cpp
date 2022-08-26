#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        unordered_map<int, int> um;
        int b = INT32_MAX, e = INT32_MIN;
        for (auto & num : nums) {
            b = min(b, num);
            e = max(e, num);
            um[num]++;
        }
        int t1 = 0, t2 = um[b] * b;
        for (int i = b + 1; i <= e; i++) {
            t1 = max(t1 + um[i] * i, t2);
            swap(t1, t2);
        }
        return max(t1, t2);
    }
};