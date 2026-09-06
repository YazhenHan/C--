public class CountGoodRotations {
    public int countGoodRotations(int[] nums) {
        int mid = nums.length / 2, total = nums.length;
        long left = 0, right = 0;
        for (int i = 0; i < nums.length; i++) {
            if (i < mid) left += nums[i];
            else right += nums[i];
        }
        int ans = 0;
        for (int i = 0; i < nums.length; i++) {
            if (left > right) ans++;
            left += nums[(mid + i + total) % total];
            left -= nums[(i + total) % total];
            right += nums[(i + total) % total];
            right -= nums[(mid + i + total) % total];
        }
        return ans;
    }
}
