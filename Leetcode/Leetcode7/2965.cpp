#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int> ans;
        unordered_set<int> us;
        for (auto& row : grid) {
            for (auto& column : row) {
                if (us.count(column))
                    ans.push_back(column);
                else
                    us.insert(column);
            }
        }
        for (int i = 1; i <= grid.size() * grid.size(); i++) {
            if (!us.count(i)) {
                ans.push_back(i);
                break;
            }
        }
        return ans;
    }
};