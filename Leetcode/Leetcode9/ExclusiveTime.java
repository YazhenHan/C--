package Leetcode.Leetcode9;

import java.util.Arrays;
import java.util.List;
import java.util.Stack;

public class ExclusiveTime {
    record Log(int func, String flag, int time) {}
    private Log parseLog(String log) {
        int func = Integer.parseInt(log.substring(0, log.indexOf(":")));
        String flag = log.substring(log.indexOf(":") + 1, log.lastIndexOf(":"));
        int time = Integer.parseInt(log.substring(log.lastIndexOf(":") + 1));
        Log l = new Log(func, flag, time);
        return l;
    }
    public int[] exclusiveTime(int n, List<String> logs) {
        int[] ans = new int[n];
        Arrays.fill(ans, 0);
        Stack<Log> stack = new Stack<>();
        stack.push(parseLog(logs.getFirst()));
        for (int i = 1; i < logs.size(); i++) {
            Log right = parseLog(logs.get(i));
            if (stack.empty()) {
                stack.push(right);
                continue;
            }
            Log left = stack.peek();
            if (right.flag.equals("start")) {
                ans[left.func] += right.time - left.time;
                stack.push(right);
            } else {
                ans[left.func] += right.time - left.time + 1;
                stack.pop();
                if (!stack.empty()) {
                    Log l = stack.pop();
                    stack.push(new Log(l.func, l.flag, right.time + 1));
                }
            }
        }
        return ans;
    }
}
