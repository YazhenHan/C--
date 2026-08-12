package Leetcode.Leetcode10;

import java.util.HashMap;
import java.util.Map;

public class MaxSubarrayLength {
    public int maxSubarrayLength(int[] nums, int k) {
        Map<Integer, Integer> map = new HashMap<>();
        int left = 0, right = 0, ans = 0;
        while (right < nums.length) {
            if (map.containsKey(nums[right]) && map.get(nums[right]) == k) {
                while (true) {
                    map.put(nums[left], map.get(nums[left]) - 1);
                    left++;
                    if (nums[left - 1] == nums[right]) break;
                }
            }
            map.put(nums[right], map.containsKey(nums[right]) ? map.get(nums[right]) + 1 : 1);
            right++;
            ans = Math.max(ans, right - left);
        }
        return ans;
    }
}
