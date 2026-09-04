import java.util.Arrays;

public class FirstStableIndex {
    public int firstStableIndex(int[] nums, int k) {
        int[] maxIs = new int[nums.length];
        int[] minIs = new int[nums.length];
        Arrays.fill(maxIs, Integer.MIN_VALUE);
        Arrays.fill(minIs, Integer.MAX_VALUE);

        int temp = Integer.MIN_VALUE;
        for (int i = 0; i < nums.length; i++) {
            temp = Math.max(temp, nums[i]);
            maxIs[i] = temp;
        }
        temp = Integer.MAX_VALUE;
        for (int i = nums.length - 1; i >= 0; i--) {
            temp = Math.min(temp, nums[i]);
            minIs[i] = temp;
        }

        for (int i = 0; i < nums.length; i++) {
            if (maxIs[i] - minIs[i] <= k) return i;
        }
        return -1;
    }
}
