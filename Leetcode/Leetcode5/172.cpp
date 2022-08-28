class Solution {
public:
    int trailingZeroes(int n) {
        int ans = 0;
        for (int i = 5; i <= n; i++)
            for (int j = i; j % 5 == 0; j /= 5)
                ans++;
        return ans;
    }
};

class Solution {
public:
    int trailingZeroes(int n) {
        int ans = 0;
        while (n != 0) {
            n /= 5;
            ans += n;
        }
        return ans;
    }
};