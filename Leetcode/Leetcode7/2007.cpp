#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        if (changed.size() % 2 != 0) { return vector<int>(); }
        sort(changed.begin(), changed.end());
        unordered_map<int, int> um;
        for (int i = 0; i < changed.size(); i++) {
            if (um.count(changed[i]))
                um[changed[i]]++;
            else
                um[changed[i]] = 1;
        }
        vector<int> ans;
        for (int i = 0; i < changed.size(); i++) {
            if (um[changed[i]] == 0) continue;
            if (um.count(changed[i] * 2) && um[changed[i] * 2] > 0) {
                um[changed[i]]--;
                um[changed[i] * 2]--;
                ans.push_back(changed[i]);
            } else {
                return vector<int>();
            }
        }
        return ans;
    }
};