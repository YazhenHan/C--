package Leetcode.Leetcode10;

import java.util.Arrays;

class StoneGameII {
    private int[][][] flags;
    private int stoneGame(int[] piles, int j, int depth, int m) {
        if (j >= piles.length) return 0;

        if (depth % 2 == 1) {
            if (flags[j][m][0] != -1) return flags[j][m][0];

            int ans = Integer.MIN_VALUE, temp = 0;
            for (int x = 1; x <= 2 * m && j + x - 1 < piles.length; x++) {
                temp += piles[j + x - 1];
                ans = Math.max(ans, temp + stoneGame(piles, j + x, depth + 1, Math.max(m, x)));
            }
            flags[j][m][0] = ans;

            return ans;
        } else {
            if (flags[j][m][1] != -1) return flags[j][m][1];

            int ans = Integer.MAX_VALUE;
            for (int x = 1; x <= 2 * m; x++) {
                ans = Math.min(ans, stoneGame(piles, j + x, depth + 1, Math.max(m, x)));
            }
            flags[j][m][1] = ans;

            return ans;
        }
    }

    public int stoneGameII(int[] piles) {
        flags = new int[piles.length][piles.length * 2][2];
        for (int[][] row : flags) {
            for (int[] r : row)
            Arrays.fill(r, -1);
        }

        int ans = 0;
        ans = stoneGame(piles, 0, 1, 1);
        return ans;
    }
}
