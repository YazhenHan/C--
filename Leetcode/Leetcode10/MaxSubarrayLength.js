var maxSubarrayLength = function(nums, k) {
    const map = new Map();
    let left = 0, right = 0, ans = 0;
    while (right < nums.length) {
        if (map.has(nums[right]) && map.get(nums[right]) == k) {
            while (true) {
                map.set(nums[left], map.get(nums[left]) - 1);
                left++;
                if (nums[left - 1] == nums[right]) break;
            }
        }
        map.set(nums[right], map.has(nums[right]) ? map.get(nums[right]) + 1 : 1);
        right++;
        ans = Math.max(ans, right - left);
    }
    return ans;
};