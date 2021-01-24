#include <vector>

using namespace std;

class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<int> flags(N, 0);
        for (auto t : trust)
        {
            flags[t[0] - 1]--;
            flags[t[1] - 1]++;
        }
        for (size_t i = 0; i < N; i++)
            if (flags[i] == N - 1)
                return i + 1;
        return -1;
    }
};