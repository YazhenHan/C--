package Leetcode.Leetcode10;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class LongestSubarray {
    private List<Integer> getPrimeFactors(int num) {
        List<Integer> factors = new ArrayList<>();

        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0) {
                factors.add(i);

                while (num % i == 0) {
                    num /= i;
                }
            }
        }

        if (num > 1) {
            factors.add(num);
        }

        return factors;
    }

    public int longestSubarray(int[] nums, int k) {
        Map<Integer, List<Integer>> map = new HashMap<>();
        for (int num : nums) {
            map.computeIfAbsent(num, this::getPrimeFactors);
        }

        int left = 0, right = 0, ans = 0;
        Map<Integer, Integer> map2 = new HashMap<>();
        while (right < nums.length) {
            for (int num : map.get(nums[right])) {
                if (map2.containsKey(num)) map2.put(num, map2.get(num) + 1);
                else map2.put(num, 1);
            }
            while (map2.size() > k) {
                for (int num : map.get(nums[left])) {
                    map2.put(num, map2.get(num) - 1);
                    if (map2.get(num) == 0) map2.remove(num);
                }
                left++;
            }
            right++;
            ans = Math.max(ans, right - left);
        }
        return ans;
    }
}
