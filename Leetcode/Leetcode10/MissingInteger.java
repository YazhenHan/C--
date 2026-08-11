package Leetcode.Leetcode10;

import java.util.HashSet;
import java.util.Set;

public class MissingInteger {
    public int missingInteger(int[] nums) {
        Set<Integer> set = new HashSet<>();
        for (int num : nums) set.add(num);
        int ans = nums[0];
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] == nums[i - 1] + 1) {
                ans += nums[i];
            } else {
                break;
            }
        }
        while (set.contains(ans)) ans++;
        return ans;
    }
}
