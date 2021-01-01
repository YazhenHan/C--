#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
        int left = 0;
        unordered_map<string, int> umap;
        if (B.size() > 0)
        {
            A.push_back(' ');
            A.append(B);
        }
        for (int right = 0; right < A.size(); right++)
        {
            if (right + 1 == A.size() || A[right + 1] == ' ')
            {
                string temp = A.substr(left, right - left + 1);
                ++umap[temp];
                left = right + 2;
                right = left - 1;
            }
        }

        vector<string> ans;
        for (auto temp : umap)
            if (temp.second == 1)
                ans.push_back(temp.first);
        return ans;
    }
};