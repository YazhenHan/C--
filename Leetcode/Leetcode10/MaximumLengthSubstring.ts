function maximumLengthSubstring(s: string): number {
    const map = new Map();
    let left = 0, right = 0, ans = 0;
    while (right < s.length) {
        if (map.has(s.charAt(right)) && map.get(s.charAt(right)) == 2) {
            while (true) {
                map.set(s.charAt(left), map.get(s.charAt(left)) - 1);
                left++;
                if (s.charAt(left - 1) === s.charAt(right)) break;
            }
        }
        if (map.has(s.charAt(right))) map.set(s.charAt(right), map.get(s.charAt(right)) + 1);
        else map.set(s.charAt(right), 1);
        right++;
        ans = Math.max(ans, right - left);
    }
    return ans;
};