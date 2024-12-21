#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        sort(score.begin(), score.end(), [&](const vector<int> & v1, const vector<int> & v2) {
            return v1[k] > v2[k];
        });
        return score;
    }
};