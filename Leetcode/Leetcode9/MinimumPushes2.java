package Leetcode.Leetcode9;

import java.util.Arrays;

public class MinimumPushes2 {
    public int minimumPushes(String word) {
        int[] is = new int[26];
        Arrays.fill(is, 0);
        
        for (int i = 0; i < word.length(); i++) {
            is[word.charAt(i) - 'a']++;
        }

        Arrays.sort(is);

        int ans = 0;
        for (int i = 0; i < 8; i++) {
            ans += is[25 - i];
        }
        for (int i = 8; i < 16; i++) {
            ans += is[25 - i] * 2;
        }
        for (int i = 16; i < 24; i++) {
            ans += is[25 - i] * 3;
        }
        for (int i = 24; i < 26; i++) {
            ans += is[25 - i] * 4;
        }
        return ans;
    }
}