#include <vector>

using namespace std;

class Solution {
public:
    int findWinningPlayer(vector<int>& skills, int k) {
        int maxNum = skills[0], temp = 0, ans = 0;
        for (int i = 1; i < skills.size(); i++) {
            if (skills[i] < maxNum) {
                temp++;
            } else {
                maxNum = skills[i];
                temp = 1;
                ans = i;
            }
            if (temp == k) break;
        }
        return ans;
    }
};