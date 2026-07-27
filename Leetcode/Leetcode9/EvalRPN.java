package Leetcode.Leetcode9;

import java.util.Stack;

public class EvalRPN {
    private boolean isInteger(String str) {
        if (str == null || str.isBlank()) return false;
        try {
            Integer.parseInt(str);
            return true;
        } catch (NumberFormatException e) {
            return false;
        }
    }

    public int evalRPN(String[] tokens) {
        Stack<Integer> s1 = new Stack<>();
        for (String token : tokens) {
            if (isInteger(token)) {
                s1.push(Integer.parseInt(token));
            } else {
                int a = s1.pop(), b = s1.pop();
                switch (token) {
                    case "+":
                        s1.push(a + b);
                        break;
                    case "-":
                        s1.push(b - a);
                        break;
                    case "*":
                        s1.push(a * b);
                        break;
                    default:
                        s1.push(b / a);
                        break;
                }
            }
        }
        return s1.pop();
    }
}
