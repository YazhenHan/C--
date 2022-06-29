#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_map<int, int> um;
        int ans = 100000;
        for (int i = 0; i < cards.size(); i++) {
            if (um.count(cards[i]))
                ans = min(ans, i - um[cards[i]]);
            um[cards[i]] = i;
        }
        return ans == 100000 ? -1 : ans + 1;
    }
};