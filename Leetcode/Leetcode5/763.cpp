#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> ans;
        unordered_map<char, int> um;
        for (int i = 0; i < s.size(); i++) {
            if (!um.count(s[i])) {
                ans.push_back(1);
                um.insert({s[i], ans.size() - 1});
            } else {
                ans[um[s[i]]]++;
                int j;
                for (j = i - 1; j > 0 && um[s[j]] != um[s[i]]; j--)
                    ans[um[s[i]]]++;
                for (int k = i - 1; k > j; k--)
                    um[s[k]] = um[s[i]];
                for (j = ans.size() - 1; j > um[s[i]]; j--)
                    ans.pop_back();
            }
        }
        return ans;
    }
};