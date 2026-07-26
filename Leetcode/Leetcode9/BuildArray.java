package Leetcode.Leetcode9;

import java.util.ArrayList;
import java.util.List;

public class BuildArray {
    public List<String> buildArray(int[] target, int n) {
        List<String> ans = new ArrayList<>();
        for (int i = 1, temp = 0; i <= n && temp < target.length; i++) {
            if (target[temp] == i) {
                ans.add("Push");
                temp++;
            } else {
                ans.add("Push");
                ans.add("Pop");
            }
        }
        return ans;
    }
}
