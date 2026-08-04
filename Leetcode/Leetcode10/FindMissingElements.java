package Leetcode.Leetcode10;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class FindMissingElements {
    public List<Integer> findMissingElements(int[] nums) {
        Arrays.sort(nums);
        List<Integer> ans = new ArrayList<>();
        int temp = nums[0] + 1;
        for (int i = 1; i < nums.length; i++) {
            while (temp != nums[i]) {
                ans.add(temp);
                temp++;
            }
            temp++;
        }
        return ans;
    }
}