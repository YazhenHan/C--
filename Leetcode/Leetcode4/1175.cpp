class Solution {
private:
    bool isZhi(int n) {
        if (n == 1) return false;
        for (int i = 2; i <= n / 2; i++)
            if (n % i == 0)
                return false;
        return true;
    }
public:
    int numPrimeArrangements(int n) {
        int a = 0;
        for (int i = 1; i <= n; i++)
            if (isZhi(i))
                a++;
        long ans = 1;
        for (int i = 1; i <= a; i++)
            ans = (ans * i) % 1000000007;
        for (int i = 1; i <= n - a; i++)
            ans = (ans * i) % 1000000007;
        return ans;
    }
};