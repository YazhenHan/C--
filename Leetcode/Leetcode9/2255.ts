function countPrefixes(words: string[], s: string): number {
    let count = 0;
    for (let word of words) {
        if (s.startsWith(word)) {
            count++;
        }
    }
    return count;
};