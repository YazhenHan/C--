package Leetcode.Leetcode9;

import java.util.Stack;

public class FinalPrices {
    public int[] finalPrices(int[] prices) {
        Stack<int[]> stack = new Stack<>();
        int[] ans = prices.clone();
        for (int i = 0; i < prices.length; i++) {
            while (!stack.isEmpty() && prices[i] <= stack.peek()[1]) {
                ans[stack.peek()[0]] = prices[stack.peek()[0]] - prices[i];
                stack.pop();
            }
            stack.push(new int[]{i, prices[i]});
        }
        return ans;
    }
}
