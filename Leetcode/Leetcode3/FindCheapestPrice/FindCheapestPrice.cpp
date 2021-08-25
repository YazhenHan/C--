#include <vector>
#include <utility>
#include <tuple>
#include <iostream>

using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        int ans = INT32_MAX;
        vector<vector<pair<int, int>>> adjust(n); // i-th to i-j-th cost
        for (auto& flight : flights)
            adjust[flight[0]].push_back({ flight[1], flight[2] });
        vector<tuple<int, int, int, int>> v; // i-th cost depth pre
        tuple<int, int, int, int> s(src, 0, -1, -1);
        v.push_back(s);
        for (int i = 0; i < v.size(); i++) {
            if (dst == get<0>(v[i])) { ans = min(ans, get<1>(v[i])); continue; }
            if (k == get<2>(v[i])) continue;

            for (auto& a : adjust[get<0>(v[i])]) {
                bool flag = false;
                int t = i;
                while (t != -1) {
                    if (a.first == get<0>(v[t])) flag = true;
                    t = get<3>(v[t]);
                }
                if (flag) continue;

                tuple<int, int, int, int> tt(a.first, a.second + get<1>(v[i]), 1 + get<2>(v[i]), i);
                v.push_back(tt);
            }
        }
        if (ans == INT32_MAX) ans = -1;
        return ans;
    }
};

int main() {
    vector<vector<int>> flights = {{4,7,10},{9,6,5},{7,4,4},{6,2,10},{6,8,6},{7,9,4},{1,5,4},{1,0,4},{9,7,3},{7,0,5},{6,5,8},{1,7,6},{4,0,9},{5,9,1},{8,7,3},{1,2,6},{4,1,5},{5,2,4},{1,9,1},{7,8,10},{0,4,2},{7,2,8}};;
    cout << Solution().findCheapestPrice(10, flights, 6, 0, 7) << endl;
    return 0;
}