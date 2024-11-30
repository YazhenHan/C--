class Solution {
public:
    int climbStairs(int n) {
        if (n <= 3) return n;
        int t1 = 1, t2 = 2, ans;
        for (int i = 3; i <= n; i++) {
            ans = t1 + t2;
            t1 = t2;
            t2 = ans;
        }
        return ans;
    }
};