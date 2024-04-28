#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
private:
    unordered_map<int, vector<int>> um;
public:
    vector<int> beautifulArray(int n) {
        if (n == 1) return {1};
        if (um.count(n)) return um[n];
        vector<int> left = beautifulArray((n + 1) / 2);
        vector<int> right = beautifulArray(n / 2);
        vector<int> ans;
        for (int i = 0; i < left.size(); i++)
            ans.push_back(2 * left[i] - 1);
        for (int i = 0; i < right.size(); i++)
            ans.push_back(2 * right[i]);
        um.insert({n, ans});
        return ans;
    }
};