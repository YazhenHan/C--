#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<unordered_set<int>> vu(numCourses);
        for (const auto & prerequisite : prerequisites)
            vu[prerequisite[0]].insert(prerequisite[1]);
        
        vector<bool> filter(numCourses, true);
        queue<int> q;
        for (int i = 0; i < numCourses; i++)
            if (vu[i].empty() && filter[i]) {
                q.push(i);
                filter[i] = false;
            }
        
        vector<int> ans;
        while (!q.empty()) {
            auto prerequisite = q.front();
            q.pop();
            ans.push_back(prerequisite);
            for (int i = 0; i < numCourses; i++) {
                vu[i].erase(prerequisite);
                if (vu[i].empty() && filter[i]) {
                    q.push(i);
                    filter[i] = false;
                }
            }
        }

        return ans.size() == numCourses ? ans : vector<int>();
    }
};