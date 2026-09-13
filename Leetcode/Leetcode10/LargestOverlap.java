public class LargestOverlap {
    public int largestOverlap(int[][] img1, int[][] img2) {
        int n = img1.length;
        int ans = 0;
        for (int i = -(n - 1); i <= n - 1; i++) {
            for (int j = -(n - 1); j <= n - 1; j++) {
                int temp = 0;
                for (int k = 0; k < n; k++) {
                    for (int l = 0; l < n; l++) {
                        if (img1[k][l] == 1 && k + i >= 0 && k + i < n && l + j >= 0 && l + j < n && img2[k + i][l + j] == 1) temp++;
                    }
                }
                ans = Math.max(ans, temp);
            }
        }
        return ans;
    }
}
