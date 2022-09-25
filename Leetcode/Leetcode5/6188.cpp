#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        unordered_map<int, string> um;
        for (int i = 0; i < heights.size(); i++)
            um.insert({heights[i], names[i]});
        sort(heights.begin(), heights.end(), greater<int>());
        vector<string> ans;
        for (int i = 0; i < heights.size(); i++)
            ans.push_back(um[heights[i]]);
        return ans;
    }
};