package Leetcode.Leetcode9;

public class MaxProduct1464 {
    public int maxProduct(int[] nums) {
        int a = Math.max(nums[0], nums[1]), b = Math.min(nums[0], nums[1]);
        for (int i = 2; i < nums.length; i++) {
            if (nums[i] >= a) {
                b = a;
                a = nums[i];
            } else if (nums[i] >= b) {
                b = nums[i];
            }
        }
        return (a - 1) * (b - 1);
    }
}
