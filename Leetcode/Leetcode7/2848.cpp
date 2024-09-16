#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        unordered_set<int> ans;
        for (auto & num : nums) {
            for (int i = num[0]; i <= num[1]; i++)
                ans.insert(i);
        }
        return ans.size();
    }
};