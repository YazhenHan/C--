class Solution {
public:
    int numWays(int n) {
        if (n == 0) return 1;
        if (n <= 2) return n;
        int t1 = 1, t2 = 2;
        for (int i = 2; i < n; i++) {
            int t = (t1 % 1000000007 + t2 % 1000000007) % 1000000007;
            t1 = t2;
            t2 = t;
        }
        return t2;
    }
};