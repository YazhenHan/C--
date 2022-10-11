#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, unordered_set<int>> umsi;
        unordered_map<int, unordered_set<int>> umso;
        for (const auto & prerequisite : prerequisites) {
            umsi[prerequisite[1]].insert(prerequisite[0]);
            umso[prerequisite[0]].insert(prerequisite[1]);
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++)
            if (!umso.count(i))
                q.push(i);
        
        int count = 0;
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            count++;
            if (umsi.count(v)) {
                for (auto i : umsi[v]) {
                    umso[i].erase(v);
                    if (umso[i].empty())
                        q.push(i);
                }
            }
        }

        return count == numCourses;
    }
};