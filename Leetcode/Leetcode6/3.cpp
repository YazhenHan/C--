#include <vector>
#include <unordered_map>

using namespace std;


// Out of time
class Solution {
public:
    int beautifulBouquet(vector<int>& flowers, int cnt) {
        int ans = 0;
        for (int i = 0; i < flowers.size(); i++) {
            unordered_map<int, int> um;
            for (int j = i; j >= 0; j--) {
                um[flowers[j]]++;
                if (um[flowers[j]] > cnt)
                    break;
                ans = (ans + 1) % 1000000007;
            }
        }
        return ans;
    }
};

class Solution {
public:
    int beautifulBouquet(vector<int>& flowers, int cnt) {
        int l = 0, r = 0, ans = 0;
        unordered_map<int, int> um;
        while (r < flowers.size()) {
            um[flowers[r]]++;
            while (um[flowers[r]] > cnt) {
                um[flowers[l]]--;
                l++;
            }
            ans = (ans + r - l + 1) % 1000000007;
            r++;
        }
        return ans;
    }
};