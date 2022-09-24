#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int transportationHub(vector<vector<int>>& path) {
        vector<int> in(1001, 0), out(1001, 0);
        for (auto & p : path) {
            in[p[1]]++;
            out[p[0]]++;
        }
        int c = 0;
        for (int i = 0; i < 1001; i++) {
            if (in[i] != 0 || out[i] != 0)
                c++;
        }
        for (int i = 0; i < 1001; i++) {
            if (in[i] == c - 1 && out[i] == 0)
                return i;
        }
        return -1;
    }
};