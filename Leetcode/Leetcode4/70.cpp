class Solution {
public:
    int climbStairs(int n) {
        if (n == 1 || n == 2) return n;
        int temp1 = 1, temp2 = 2, ans = temp1 + temp2;
        for (int i = 3; i < n; i++) {
            temp1 = temp2;
            temp2 = ans;
            ans = temp1 + temp2;
        }
        return ans;
    }
};