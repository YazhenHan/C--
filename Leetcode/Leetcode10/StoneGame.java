package Leetcode.Leetcode10;

import java.util.Arrays;

public class StoneGame {
    private int[][] flags;

    private int stoneGame(int[] piles, int left, int right, int depth) {
        if (left > right) return 0;
        if (flags[left][right] != 0) {
            return flags[left][right];
        }
        int ans;
        if (depth % 2 == 1) {
            ans = Math.max(piles[left] + stoneGame(piles, left + 1, right, depth + 1), piles[right] + stoneGame(piles, left, right - 1, depth + 1));
        } else {
            ans = Math.min(stoneGame(piles, left + 1, right, depth + 1), stoneGame(piles, left, right - 1, depth + 1));
        }
        flags[left][right] = ans;
        return ans;
    }

    public boolean stoneGame(int[] piles) {
        flags = new int[piles.length][piles.length];
        int sum = Arrays.stream(piles).sum();
        return stoneGame(piles, 0, piles.length - 1, 1) > sum - stoneGame(piles, 0, piles.length - 1, 1);
    }
}
