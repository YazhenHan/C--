#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    struct ps {
        int position;
        int speed;
        ps(int p, int s) : position(p), speed(s) {}
        bool operator < (const ps& temp) const {
            return position < temp.position;
        }
    };
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<ps> pss;
        for (int i = 0; i < position.size(); i++)
            pss.push_back(ps(position[i], speed[i]));
        sort(pss.begin(), pss.end());

        int ans = 0;
        float t = 0;
        for (int i = pss.size() - 1; i >= 0; i--) {
            float temp = (target - pss[i].position) / (float)pss[i].speed;
            if (temp > t) {
                ans++;
                t = temp;
            }
        }
        return ans;
    }
};