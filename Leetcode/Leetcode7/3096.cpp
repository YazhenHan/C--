#include <vector>

using namespace std;

class Solution {
public:
    int minimumLevels(vector<int>& possible) {
        int total = 0;
        for (auto p : possible) {
            if (p == 1) total++;
            else total--;
        }
        int ans = 0, left = 0, right = total;
        while (ans < possible.size()) {
            if (possible[ans] == 1) { left++; total--; }
            else { left--; total++; }
            if (left > total) break;
            ans++;
        }
        if (ans >= possible.size() - 1) return -1;
        return ans + 1;
    }
};