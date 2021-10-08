#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        vector<unordered_set<int>> lann(n);
        vector<unordered_set<int>> nlan(languages.size());
        for (int i = 0; i < languages.size(); i++) {
            for (int j = 0; j < languages[i].size(); j++) {
                lann[languages[i][j] - 1].insert(i);
                nlan[i].insert(languages[i][j] - 1);
            }
        }

        vector<int> nms(n, 0);
        int ans = 0, m = 0, mmax = 0;
        vector<bool> flags(languages.size(), true);
        for (int i = 0; i < friendships.size(); i++) {
            bool flag = false;
            for (int j = 0; j < n; j++) {
                if (lann[j].find(friendships[i][0] - 1) != lann[j].end() && lann[j].find(friendships[i][1] - 1) != lann[j].end()) {
                    flag = true;
                    continue;
                }
            }
            if (flag) continue;

            if (flags[friendships[i][0] - 1]) {
                for (int j = 0; j < languages[friendships[i][0] - 1].size(); j++) {
                    nms[languages[friendships[i][0] - 1][j] - 1]++;
                    mmax = max(mmax, nms[languages[friendships[i][0] - 1][j] - 1]);
                }
                flags[friendships[i][0] - 1] = false;
                m++;
            }

            if (flags[friendships[i][1] - 1]) {
                for (int j = 0; j < languages[friendships[i][1] - 1].size(); j++) {
                    nms[languages[friendships[i][1] - 1][j] - 1]++;
                    mmax = max(mmax, nms[languages[friendships[i][1] - 1][j] - 1]);
                }
                flags[friendships[i][1] - 1] = false;
                m++;
            }
        }
        
        return m - mmax;
    }
};