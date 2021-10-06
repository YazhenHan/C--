#include <vector>
#include <string>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        int n = friends.size();
        vector<bool> used(n);
        queue<int> q;
        q.push(id);
        used[id] = true;
        for (int i = 1; i <= level; ++i) {
            int span = q.size();
            for (int j = 0; j < span; j++) {
                int u = q.front();
                q.pop();
                for (int v : friends[u]) {
                    if (!used[v]) {
                        q.push(v);
                        used[v] = true;
                    }
                }
            }
        }

        unordered_map<string, int> freq;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (const string& watched : watchedVideos[u]) {
                ++freq[watched];
            }
        }

        vector<pair<string, int>> videos(freq.begin(), freq.end());
        sort(videos.begin(), videos.end(), [](const pair<string, int>& p, const pair<string, int>& q) {
            return p.second < q.second || (p.second == q.second && p.first < q.first);
        });

        vector<string> ans;
        for (const auto& video : videos) {
            ans.push_back(video.first);
        }
        return ans;
    }
};