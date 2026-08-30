import java.util.HashMap;
import java.util.Map;

class Solution {
    public int countSpecialIntegers(int[] nums) {
        Map<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i + 1 < nums.length; i++) {
            if (nums[i] != nums[i + 1]) {
                map.put(nums[i], map.containsKey(nums[i]) ? map.get(nums[i]) + 1 : 1);
            }
        }
        map.put(nums[nums.length - 1], map.containsKey(nums[nums.length - 1]) ? map.get(nums[nums.length - 1]) + 1 : 1);
        int ans = 0;
        for (Map.Entry<Integer, Integer> entry : map.entrySet()) {
            if (entry.getValue() == 1) ans++;
        }
        return ans;
    }
}