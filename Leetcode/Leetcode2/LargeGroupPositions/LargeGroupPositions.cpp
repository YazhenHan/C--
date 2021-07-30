#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int>> ans;
        int left = 0;
        for (int right = 0; right < s.size(); right++)
        {
            if (right + 1 == s.size() || s[right + 1] != s[left])
            {
                if (right - left >= 2)
                {
                    vector<int> temp = {left, right};
                    ans.push_back(temp);
                }
                left = right;
            }
        }
        return ans;
    }
};