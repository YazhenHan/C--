#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> flags(word1.size() + 1, vector<int>(word2.size() + 1, 0));
        for (int i = 1; i <= word1.size(); i++)
            for (int j = 1; j <= word2.size(); j++)
                if (word1[i - 1] == word2[j - 1])
                    flags[i][j] = flags[i - 1][j - 1] + 1;
                else
                    flags[i][j] = max(flags[i - 1][j], flags[i][j - 1]);
        return word1.size() + word2.size() - flags.back().back() * 2;
    }
};