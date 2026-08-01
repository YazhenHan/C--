package Leetcode.Leetcode9;

import java.util.Arrays;

public class PredictTheWinner {
    private int predictTheWinner(int[] nums, int left, int right, int depth) {
        if (left > right) return 0;
        
        if (depth % 2 == 1)
            return Math.max(nums[left] + predictTheWinner(nums, left + 1, right, depth + 1), nums[right] + predictTheWinner(nums, left, right - 1, depth + 1));
        else
            return Math.min(predictTheWinner(nums, left + 1, right, depth + 1), predictTheWinner(nums, left, right - 1, depth + 1));
    }

    public boolean predictTheWinner(int[] nums) {
        int ans = predictTheWinner(nums, 0, nums.length - 1, 1);
        int total = Arrays.stream(nums).sum();
        return ans >= total - ans;
    }
}
