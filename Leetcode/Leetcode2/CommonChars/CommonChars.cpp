#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        vector<vector<int>> flags;
        for (auto s : A)
        {
            vector<int> temp(26, 0);
            for (auto c : s)
                temp[c - 'a']++;
            flags.push_back(temp);
        }
        vector<string> ans;
        for (int i = 0; i < 26; i++)
        {
            int temp = INT32_MAX;
            for (int j = 0; j < A.size(); j++)
            {
                if (flags[j][i] < temp)
                {
                    temp = flags[j][i];
                }
            }
            for (int j = 0; j < temp; j++)
            {
                string t;
                t.push_back(i + 'a');
                ans.push_back(t);
            }
        }
        return ans;
    }
};