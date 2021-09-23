#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> nums(s.length(), 0);
        int ans = 0;
        for (auto c : s) {
            nums[c - 'a']++;
            ans++;
        }
        for (auto c : t) {
            if (nums[c - 'a'] > 0) {
                nums[c - 'a']--;
                ans--;
            }
        }
        return ans;
    }
};