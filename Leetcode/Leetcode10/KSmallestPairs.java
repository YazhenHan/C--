package Leetcode.Leetcode10;

import java.util.ArrayList;
import java.util.List;
import java.util.PriorityQueue;

public class KSmallestPairs {
    public List<List<Integer>> kSmallestPairs(int[] nums1, int[] nums2, int k) {
        PriorityQueue<int[]> pq = new PriorityQueue<>(k, (a, b) -> nums1[a[0]] + nums2[a[1]] - nums1[b[0]] - nums2[b[1]]);
        for (int i = 0; i < Math.min(k, nums1.length); i++) pq.offer(new int[]{i, 0});
        List<List<Integer>> ans = new ArrayList<>();
        for (int i = 0; i < k && !pq.isEmpty(); i++) {
            int[] temp = pq.poll();
            List<Integer> list = new ArrayList<>();
            list.add(nums1[temp[0]]);
            list.add(nums2[temp[1]]);
            ans.add(list);
            if (temp[1] + 1 < nums2.length) {
                pq.offer(new int[]{temp[0], temp[1] + 1});
            }
        }
        return ans;
    }
}
