class Solution {
public:
    int commonFactors(int a, int b) {
        int ans = 0, t = min(a, b), t2 = max(a, b);
        for (int i = 1; i <= sqrt(t); i++){
            if (t % i == 0 && t2 % i == 0)
                ans++;
            if (i != t / i && t % i == 0 && t2 % (t / i) == 0)
                ans++;
        }
        return ans;
    }
};