package Leetcode.Leetcode10;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.Set;
import java.util.List;

public class FindDisappearedNumbers {
    public List<List<Integer>> findDisappearedNumbers(int[] nums, int lower, int upper) {
        Set<Integer> set = new HashSet<>();
        for (int num : nums) set.add(num);
        List<List<Integer>> ans = new ArrayList<>();
        int left = lower;
        while (set.contains(left)) left++;
        int right = left;
        while (right <= upper) {
            if (set.contains(right)) {
                List<Integer> list = new ArrayList<>();
                list.add(left);
                list.add(right - 1);
                ans.add(list);

                while (set.contains(right)) right++;
                left = right;
            }
            right++;
        }
        if (left <= upper) {
            List<Integer> list = new ArrayList<>();
            list.add(left);
            list.add(right - 1);
            ans.add(list);
        }
        return ans;
    }
}
