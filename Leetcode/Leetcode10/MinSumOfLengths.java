import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

public class MinSumOfLengths {
    public int minSumOfLengths(int[] arr, int target) {
        int[] sum = arr.clone();
        for (int i = 1; i < arr.length; i++) {
            sum[i] = sum[i - 1] + arr[i];
        }
        Map<Integer, Integer> map = new HashMap<>();
        map.put(0, -1);
        int[] dp = new int[arr.length];
        Arrays.fill(dp, -1);
        int ans = Integer.MAX_VALUE;
        for (int i = 0; i < sum.length; i++) {
            if (map.containsKey(sum[i] - target)) {
                if (i - 1 >= 0 && dp[i - 1] != -1) {
                    if (dp[map.get(sum[i] - target)] != -1)
                    ans = Math.min(ans, dp[map.get(sum[i] - target)] + i - map.get(sum[i] - target));
                    dp[i] = Math.min(dp[i - 1], i - map.get(sum[i] - target));
                } else {
                    dp[i] = i - map.get(sum[i] - target);
                }
            } else {
                if (i - 1 >= 0)
                    dp[i] = dp[i - 1];
            }
            map.put(sum[i], i);
        }
        return ans == Integer.MAX_VALUE ? -1 : ans;
    }
}
