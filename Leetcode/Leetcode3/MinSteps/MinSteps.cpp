class Solution {
public:
    int minSteps(int n) {
        int ans = 0;
        while (n > 1) {
            for (int s = n / 2; s >= 1; s--) {
                if (n % s == 0) {
                    ans += n / s;
                    n = s;
                    break;
                }
            }
        }
        return ans;
    }
};