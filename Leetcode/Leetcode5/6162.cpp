#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int ans = 0, m = 0, p = 0, g = 0;
        for (int i = 0; i < garbage.size(); i++) {
            for (int j = 0; j < garbage[i].size(); j++) {
                switch (garbage[i][j])
                {
                case 'M':
                    m = max(m, i);
                    ans++;
                    break;
                case 'P':
                    p = max(p, i);
                    ans++;
                    break;
                default:
                    g = max(g, i);
                    ans++;
                    break;
                }
            }
        }
        for (int i = 1; i < travel.size(); i++)
            travel[i] = travel[i - 1] + travel[i];
        if (m > 0)
            ans += travel[m - 1];
        if (p > 0)
            ans += travel[p - 1];
        if (g > 0)
            ans += travel[g - 1];
        return ans;
    }
};