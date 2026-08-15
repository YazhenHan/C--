function longestSubsequence(nums: number[]): number {
    let ans = 0;
    let flag = false;
    for (const element of nums) {
        ans ^= element;
        if (element !== 0) flag = true;
    }
    if (ans !== 0) return nums.length;
    if (flag) return nums.length - 1;
    return 0;
};