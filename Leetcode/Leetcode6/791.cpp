#include <string>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    string customSortString(string order, string s) {
        vector<int> comp(26, INT32_MAX);
        for (int i = 0; i < order.size(); i++)
            comp[order[i] - 'a'] = i;
        sort(s.begin(), s.end(), [comp](char a, char b) {
            return comp[a - 'a'] < comp[b - 'a'];
        });
        return s;
    }
};