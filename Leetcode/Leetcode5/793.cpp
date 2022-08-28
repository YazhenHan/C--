class Solution {
private:
    int trailingZeroes(int n) {
        int ans = 0;
        while (n != 0) {
            n /= 5;
            ans += n;
        }
        return ans;
    }
public:
    int preimageSizeFZF(int k) {
        int t = 1;
        while (trailingZeroes(t) < k)
            t *= 5;
        return t;
    }
};