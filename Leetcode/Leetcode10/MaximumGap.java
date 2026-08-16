package Leetcode.Leetcode10;

public class MaximumGap {
    public int maximumGap(String skill, String station) {
        int[] dp = new int[skill.length()];
        int i = skill.length() - 1, j = station.length() - 1;
        while (i >= 0 && j >= 0) {
            if (skill.charAt(i) == station.charAt(j)) {
                dp[i] = j;
                i--;
            }
            j--;
        }
        int ans = 0;
        i = 0;
        j = 0;
        while (i + 1 < skill.length()) {
            if (skill.charAt(i) == station.charAt(j)) {
                ans = Math.max(ans, dp[i + 1] - j);
                i++;
            }
            j++;
        }
        return ans;
    }
}
