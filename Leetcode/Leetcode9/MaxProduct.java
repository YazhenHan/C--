package Leetcode.Leetcode9;

public class MaxProduct {
    public int maxProduct(int n) {
        int a = n % 10;
        n /= 10;
        int b = n % 10;
        n /= 10;
        int aa = Math.max(a, b), bb = Math.min(a, b);
        int ans = aa * bb;
        while (n != 0) {
            int temp = n % 10;
            if (temp >= aa) {
                bb = aa;
                aa = temp;
            } else if (temp >= bb) {
                bb = temp;
            }
            ans = aa * bb;
            n /= 10;
        }
        return ans;
    }
}
