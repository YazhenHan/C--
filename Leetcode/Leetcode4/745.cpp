#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class WordFilter {
private:
    unordered_map<string, int> um;
public:
    WordFilter(vector<string>& words) {
        for (int i = 0; i < words.size(); i++)
            for (int j = 1; j <= words[i].size(); j++)
                for (int k = 1; k <= words[i].size(); k++)
                    um[words[i].substr(0, j) + "#" + words[i].substr(words[i].size() - k)] = i;
    }
    
    int f(string pref, string suff) {
        if (um.count(pref + "#" + suff))
            return um[pref + "#" + suff];
        return -1;
    }
};