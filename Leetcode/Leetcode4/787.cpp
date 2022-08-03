#include <vector>
#include <queue>
#include <utility>
#include <set>

using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> vv(n);
        for (auto & flight : flights)
            vv[flight[0]].push_back({flight[1], flight[2]});

        vector<int> distTo(n);
        for (int i = 0; i < n; i++)
            distTo[i] = INT32_MAX;
        distTo[src] = 0;
        
        set<int> v;
        v.insert(src);
        for (int i = 0; i <= k; i++) {
            set<int> t = v;
            vector<int> tt = distTo;
            for (const auto & s : t) {
                for (const auto & flight : vv[s]) {
                    distTo[flight.first] = min(distTo[flight.first], tt[s] + flight.second);
                    v.insert(flight.first);
                }
            }
        }

        return distTo[dst] == INT32_MAX ? -1 : distTo[dst];
    }
};