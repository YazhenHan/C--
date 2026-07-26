package Leetcode.Leetcode9;

import java.util.Set;
import java.util.HashSet;

class Solution {
    public int[] findErrorNums(int[] nums) {
        Set<Integer> set = new HashSet<>();
        int sum = 0;
        int[] ans = new int[2];
        for (int num : nums) {
            if (set.contains(num)) {
                ans[0] = num;
            } else {
                set.add(num);
            }
            sum += num;
        }
        int goal = nums.length * (nums.length + 1) / 2;
        ans[1] = sum > goal ? ans[0] - (sum - goal) : ans[0] + (goal - sum);
        return ans;
    }
}