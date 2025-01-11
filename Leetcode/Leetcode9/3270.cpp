class Solution {
public:
    int generateKey(int num1, int num2, int num3) {
        int b1, b2, b3, b4;
        int t1 = num1, t2 = num2, t3 = num3;
        b1 = min(t1 % 10, min(t2 % 10, t3 % 10));
        t1 /= 10; t2 /= 10; t3 /=10;
        b2 = min(t1 % 10, min(t2 % 10, t3 % 10));
        t1 /= 10; t2 /= 10; t3 /=10;
        b3 = min(t1 % 10, min(t2 % 10, t3 % 10));
        t1 /= 10; t2 /= 10; t3 /=10;
        b4 = min(t1 % 10, min(t2 % 10, t3 % 10));
        int ans = ((b4 * 10 + b3) * 10 + b2) * 10 + b1;
        return ans;
    }
};