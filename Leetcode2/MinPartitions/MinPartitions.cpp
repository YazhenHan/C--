#include <string>

using namespace std;

class Solution {
public:
    int minPartitions(string n) {
        int ans = 0;
        for (auto c : n)
            ans = max(c - '0', ans);
        return ans;
    }
};