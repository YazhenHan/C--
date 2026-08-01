package Leetcode.Leetcode9;

public class TimeRequiredToBuy {
    public int timeRequiredToBuy(int[] tickets, int k) {
        int ans = 0;
        int left = 0;
        while (tickets[k] != 0) {
            if (tickets[left] != 0) {
                tickets[left]--;
                ans++;
            }
            left = (left + 1) % tickets.length;
        }
        return ans;
    }
}
