package Leetcode.Leetcode9;

public class MinimumPushes {
    public int minimumPushes(String word) {
        int ans = 0;
        int len = word.length();
        if (len <= 8) {
            ans = len;
        } else if (len <= 16) {
            ans = 8 + (len - 8) * 2;
        } else if (len <= 24) {
            ans = 24 + (len - 16) * 3;
        } else {
            ans = 48 + (len - 24) * 4;
        }
        return ans;
    }
}
