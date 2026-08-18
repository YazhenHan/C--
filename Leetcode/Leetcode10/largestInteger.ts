function largestInteger(nums: number[], k: number): number {
    if (nums.length === k) return Math.max(...nums);
    
    const map = new Map<number, number>();
    for (const element of nums) {
        if (map.has(element)) map.set(element, map.get(element)! + 1);
        else map.set(element, 1);
    }

    if (k === 1) {
        let ans = -1;
        for (const element of nums) {
            if (map.get(element) === 1) ans = Math.max(ans, element);
        }
        return ans;
    }

    let a = -1, b = -1;
    if (map.get(nums.at(-1)) === 1) a = nums.at(-1);
    if (map.get(nums[0]) === 1) b = nums[0];
    return Math.max(a, b);
};