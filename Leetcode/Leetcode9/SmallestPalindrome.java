package Leetcode.Leetcode9;

public class SmallestPalindrome {
    public String smallestPalindrome(String s) {
        int[] is = new int[26];
        for (int i = 0; i < s.length(); i++) {
            is[s.charAt(i) - 'a']++;
        }
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < is[i] / 2; j++)
                sb.append((char)('a' + i));
        }
        StringBuilder temp = new StringBuilder(sb);
        for (int i = 0; i < 26; i++) {
            if (is[i] % 2 != 0) {
                sb.append((char)('a' + i));
                sb.append(temp.reverse());
                return sb.toString();
            }
        }
        sb.append(temp.reverse());
        return sb.toString();
    }
}
