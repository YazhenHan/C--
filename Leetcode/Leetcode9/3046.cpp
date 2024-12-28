#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
        unordered_map<int, int> um;
        for (auto num : nums) {
            um[num]++;
            if (um[num] > 2) return false;
        }
        return true;
    }
};