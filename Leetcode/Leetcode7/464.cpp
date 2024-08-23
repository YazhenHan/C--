#include <unordered_map>

using namespace std;

class Solution {
private:
    unordered_map<int, bool> memo;
public:
    bool dfs(int maxChoosableInteger, int usedNumbers, int desiredTotal, int currentTotal) {
        if (memo.count(usedNumbers)) return memo[usedNumbers];
        bool ans = false;
        for (int i = 1; i <= maxChoosableInteger; i++) {
            if (((usedNumbers >> i) & 1) == 0) {
                if (i + currentTotal >= desiredTotal || !dfs(maxChoosableInteger, usedNumbers | (1 << i), desiredTotal, currentTotal + i)) {
                    ans = true;
                    break;
                }
            }
        }
        memo[usedNumbers] = ans;
        return ans;
    }
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if ((1 + maxChoosableInteger) * maxChoosableInteger / 2 < desiredTotal) return false;
        return dfs(maxChoosableInteger, 0, desiredTotal, 0);
    }
};