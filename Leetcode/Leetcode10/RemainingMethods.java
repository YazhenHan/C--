package Leetcode.Leetcode10;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;

public class RemainingMethods {
    private void remainingMethods(Map<Integer, Set<Integer>> map, int k, boolean[] flags) {
        if (flags[k]) return;
        flags[k] = true;
        if (!map.containsKey(k)) return;
        for (int i : map.get(k)) {
            remainingMethods(map, i, flags);
        }
    }

    public List<Integer> remainingMethods(int n, int k, int[][] invocations) {
        Map<Integer, Set<Integer>> map = new HashMap<>();
        for (int[] invocation : invocations) {
            if (map.containsKey(invocation[0])) {
                map.get(invocation[0]).add(invocation[1]);
            } else {
                Set<Integer> list = new HashSet<>();
                list.add(invocation[1]);
                map.put(invocation[0], list);
            }
        }
        boolean[] flags = new boolean[n];
        remainingMethods(map, k, flags);

        boolean ans = true;
        for (int i = 0; i < n; i++) {
            if (!flags[i]) {
                if (map.containsKey(i)) {
                    for (int j : map.get(i)) {
                        if (flags[j]) ans = false;
                    }
                }
            }
        }

        List<Integer> list = new ArrayList<>();
        if (ans) {
            for (int i = 0; i < n; i++) 
                if (!flags[i]) list.add(i); 
        } else {           
            for (int i = 0; i < n; i++) list.add(i);
        }
        return list;
    }
}
