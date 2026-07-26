package Leetcode.Leetcode9;

import java.util.Arrays;

public class MaximumProduct {
    public int maximumProduct(int[] nums) {
        Arrays.sort(nums);
        int n = nums.length;
        int a = nums[0] * nums[1] * nums[2];
        int b = nums[0] * nums[1] * nums[n - 1];
        int c = nums[0] * nums[n - 1] * nums[n - 2];
        int d = nums[n - 1] * nums[n - 2] * nums[n - 3];
        return Math.max(Math.max(a, b), Math.max(c, d));
    }
}
