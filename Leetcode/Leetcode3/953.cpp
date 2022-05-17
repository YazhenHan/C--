#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int hash[27];
        hash[0] = 0;
        for (int i = 0; i < order.size(); i++)
            hash[order[i] - '`'] = i + 1;
        for (int i = 0; i < words.size(); i++)
            for (int j = words[i].size(); j < 20; j++)
                words[i].push_back('`');
        for (int i = 0; i + 1 < words.size(); i++)
            for (int j = 0; j < 20; j++)
                if (hash[words[i][j] - '`'] < hash[words[i + 1][j] - '`'])
                    break;
                else if (hash[words[i][j] - '`'] > hash[words[i + 1][j] - '`'])
                    return false;
        return true;
    }
};