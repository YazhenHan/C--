class Solution {
public:
    int distributeCandies(int n, int limit) {
        int ans = 0;
        for (int i = 0; i <= min(n, limit); i++) {
            int t = n - i;
            ans += max(min(t, limit) - max(t - limit, 0) + 1, 0);
        }
        return ans;
    }
};