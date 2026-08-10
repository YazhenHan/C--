package Leetcode.Leetcode10;

public class WinnerSquareGame {
    public boolean winnerSquareGame(int n) {
        boolean[] f = new boolean[n + 1];
        for (int i = 1; i < n + 1; i++) {
            for (int j = 1; j * j <= i; j++) {
                if (!f[i - j * j]) {
                    f[i] = true;
                    break;
                }
            }
        }
        return f[n];
    }
}
