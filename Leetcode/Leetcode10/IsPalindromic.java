package Leetcode.Leetcode10;

class IsPalindromic {
    private String getO(int temp) {
        StringBuilder sb = new StringBuilder();
        while (temp != 0) {
            sb.append(temp % 2);
            temp = temp / 2;
        }
        while (sb.length() < 8) sb.append(0);
        return sb.reverse().toString();
    }

    public boolean isPalindromic(String s) {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < s.length(); i++) {
            int temp = s.charAt(i);
            sb.append(getO(temp));
        }
        String ss = sb.toString();
        for (int i = 0; i < ss.length() / 2; i++) {
            if (ss.charAt(i) != ss.charAt(ss.length() - 1 - i)) return false;
        }
        return true;
    }
}