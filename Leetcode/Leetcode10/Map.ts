function map(arr: number[], fn: (n: number, i: number) => number): number[] {
    const ans = new Array();
    for (let i = 0; i < arr.length; i++) {
        ans.push(fn(arr[i], i));
    }
    return ans;
};