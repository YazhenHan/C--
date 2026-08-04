package Leetcode.Leetcode10;

import java.util.PriorityQueue;

public class LastStoneWeight {
    public int lastStoneWeight(int[] stones) {
        PriorityQueue<Integer> pq = new PriorityQueue<>((a, b) -> b - a);
        for (int stone : stones) pq.offer(stone);
        while (pq.size() > 1) {
            int a = pq.poll();
            int b = pq.poll();
            if (a != b) pq.offer(Math.abs(a - b));
        }
        if (pq.isEmpty()) return 0;
        else return pq.poll();
    }
}
