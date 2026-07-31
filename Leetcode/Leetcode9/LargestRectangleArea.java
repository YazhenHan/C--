package Leetcode.Leetcode9;

import java.util.Stack;

public class LargestRectangleArea {
    public int largestRectangleArea(int[] heights) {
        int[] arr1 = new int[heights.length];
        int[] arr2 = new int[heights.length];
        Stack<int[]> stack1 = new Stack<>();
        Stack<int[]> stack2 = new Stack<>();
        for (int i = 0; i < heights.length; i++) {
            while (!stack1.empty() && stack1.peek()[0] >= heights[i]) {
                stack1.pop();
            }
            arr1[i] = !stack1.empty() ? stack1.peek()[1] + 1 : 0;
            stack1.push(new int[]{heights[i], i});
        }
        for (int i = heights.length - 1; i >= 0; i--) {
            while (!stack2.empty() && stack2.peek()[0] >= heights[i]) {
                stack2.pop();
            }
            arr2[i] = !stack2.empty() ? stack2.peek()[1] - 1 : heights.length - 1;
            stack2.push(new int[]{heights[i], i});
        }
        int ans = 0;
        for (int i = 0; i < heights.length; i++) {
            System.out.println(heights[i] + " " + arr1[i] + " " + arr2[i]);
            ans = Math.max(ans, (arr2[i] - arr1[i] + 1) * heights[i]);
        }
        return ans;
    }
}
