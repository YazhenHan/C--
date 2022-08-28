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

    long long help(int k) {
        long long r = 5LL * k;
        long long l = 0;
        while (l <= r) {
            long long mid = (l + r) / 2;
            if (trailingZeroes(mid) < k)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return r + 1;
    }
public:
    int preimageSizeFZF(int k) {
        return help(k + 1) - help(k);
    }
};