package Leetcode.Leetcode10;

public class SmallestNumber {
    private boolean isTrue(int k, int t) {
        int a = 1;
        while (k != 0) {
            int y = k % 10;
            a *= y;
            k /= 10;
        }
        return a % t == 0;
    }
    
    public int smallestNumber(int n, int t) {
        int k = n;
        while (!isTrue(k, t)) {
            k++;
        }
        return k;
    }
}
