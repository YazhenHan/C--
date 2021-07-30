class Solution {
private:
    bool isRight(int x) {
        int ans = 0;
        while (x != 0)
        {
            int temp = x % 2;
            temp == 1 ? ans++ : ans;
            x = x / 2;
        }
        for (int i = 2; i <= ans / 2; i++)
            if (ans % i == 0)
                return false;
        return true;
    }
public:
    int countPrimeSetBits(int L, int R) {
        int ans = 0;
        for (int i = L; i <= R; i++)
            if (isRight(i))
                ans++;
        return ans;
    }
};