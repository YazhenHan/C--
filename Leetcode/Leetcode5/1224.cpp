#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int maxEqualFreq(vector<int>& nums) {
        unordered_map<int, int> um;
        for (auto num : nums)
            um[num]++;
        unordered_map<int, int> um2;
        for (auto p : um)
            um2[p.second]++;
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (um2.size() == 1 && (um2.begin()->first == 1 || um2.begin()->second == 1))
                return i + 1;
            if (um2.size() == 2) {
                auto a = um2.begin(), b = ++um2.begin();
                if (a->first == b->first + 1 && a->second == 1 
                 || b->first == a->first + 1 && b->second == 1 
                 || a->first == 1 && a->second == 1
                 || b->first == 1 && b->second == 1)
                    return i + 1;
            }
            um2[um[nums[i]]]--;
            um2[um[nums[i]] - 1]++;
            if (um2[um[nums[i]]] == 0)
                um2.erase(um[nums[i]]);
            um[nums[i]]--;
            um2.erase(0);
        }
        return 2;
    }
};