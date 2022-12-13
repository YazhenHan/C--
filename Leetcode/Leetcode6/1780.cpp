class Solution {
public:
    bool checkPowersOfThree(int n) {
        int t = 1;
        while (t <= n)
            t *= 3;
        if (t / 3 * 2 <= n) return false;
        if (t / 3 == n) return true;
        return checkPowersOfThree(n - t / 3);
    }
};