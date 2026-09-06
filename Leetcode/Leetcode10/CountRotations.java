public class CountRotations {
    public int countRotations(String s, int k) {
        int temp = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == s.charAt((i + 1) % s.length())) {
                temp++;
            }
        }
        if (temp == k) return s.length() - temp;
        if (temp == k + 1) return temp;
        return 0;
    }
}
