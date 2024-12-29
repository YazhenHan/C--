#include <vector>
#include <string>
#include <queue>

using namespace std;

class Solution {
public:
    string rankTeams(vector<string>& votes) {
        int m = votes.front().size();
        vector<vector<int>> vv(26, vector<int>(m, 0));
        for (const string & vote : votes) {
            for (int i = 0; i < vote.size(); i++) {
                vv[vote[i] - 'A'][i]++;
            }
        }

        auto comp = [&](const char c1, const char c2) {
            for (int i = 0; i < m; i++) {
                if (vv[c1 - 'A'][i] > vv[c2 - 'A'][i]) return false;
                else if (vv[c1 - 'A'][i] < vv[c2 - 'A'][i]) return true;
            }
            return c1 > c2;
        };
        priority_queue<char, vector<char>, decltype(comp)> pq(comp);
        for (int i = 0; i < m; i++) {
            pq.push(votes.front()[i]);
        }
        string ans;
        while (!pq.empty()) {
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
    }
};