#include <vector>

using namespace std;

class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int ans = 0;
        for (int i = 0; i < arr.size(); i++) {
            int left = i, right = arr.size() - i - 1;
            int left_even = left / 2 + 1, left_odd = left % 2 == 0 ? left / 2 : left / 2 + 1,
                right_even = right / 2 + 1, right_odd = right % 2 == 0 ? right / 2 : right / 2 + 1;
            ans += (left_even * right_even + left_odd * right_odd) * arr[i];
        }
        return ans;
    }
};