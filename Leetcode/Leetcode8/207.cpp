#include <vector>
#include <unordered_map>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution {
private:
    int dfs(unordered_map<int, vector<int>> & um, vector<int> & filter, int c, vector<int> & flags) {
        if (!flags[c]) return 0;
        if (filter[c] != -1) return filter[c];

        flags[c] = 0;
        int ans = 1;
        for (auto i : um[c]) {
            if (dfs(um, filter, i, flags) == 0) {
                ans = 0;
                break;
            }
        }
        flags[c] = 1;

        filter[c] = ans;
        return filter[c];
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> um;
        for (vector<int> prerequisite : prerequisites)
            um[prerequisite[1]].emplace_back(prerequisite[0]);

        vector<int> filter(numCourses, -1);
        for (int i = 0; i < numCourses; i++) {
            vector<int> flags(numCourses, 1);
            if (dfs(um, filter, i, flags) == 0)
                return false;
        }
        return true;
    }
};