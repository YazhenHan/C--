#include <string>
#include <unordered_map>

using namespace std;

class Solution {
private:
    unordered_map<int, int> um;
    int dfs(const string & pressedKeys, int c) {
        if (um.count(c)) return um[c];
        int ans = 0;
        ans += dfs(pressedKeys, c + 1);
        if (c + 1 < pressedKeys.size() && pressedKeys[c] == pressedKeys[c + 1]) ans = (ans + dfs(pressedKeys, c + 2)) % 1000000007;
        if (c + 2 < pressedKeys.size() && pressedKeys[c] == pressedKeys[c + 1] && pressedKeys[c + 1] == pressedKeys[c + 2]) ans = (ans + dfs(pressedKeys, c + 3)) % 1000000007;
        if ((pressedKeys[c] == '7' || pressedKeys[c] == '9') && c + 3 < pressedKeys.size() && pressedKeys[c] == pressedKeys[c + 1] && pressedKeys[c + 1] == pressedKeys[c + 2] && pressedKeys[c + 2] == pressedKeys[c + 3]) ans = (ans + dfs(pressedKeys, c + 4)) % 1000000007;
        um[c] = ans % 1000000007;
        return ans;
    }

public:
    int countTexts(string pressedKeys) {
        um[pressedKeys.size()] = 1;
        return dfs(pressedKeys, 0);
    }
};