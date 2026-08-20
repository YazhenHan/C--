/**
 * @param {number[]} nums
 * @return {number[]}
 */
var resultArray = function(nums) {
    const nums1 = [], nums2 = [];
    const iterator = nums[Symbol.iterator]();
    nums1.push(iterator.next().value);
    nums2.push(iterator.next().value);
    while (true) {
        const temp = iterator.next();
        if (temp.done) break;
        if (nums1.at(-1) > nums2.at(-1)) {
            nums1.push(temp.value);
        } else {
            nums2.push(temp.value);
        }
    }
    return [...nums1, ...nums2];
};