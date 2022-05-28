#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int findClosest(vector<string>& words, string word1, string word2) {
        unordered_map<string, vector<int>> word2vec;
        for (int i = 0; i < words.size(); i++) {
            if (word2vec.count(words[i])) {
                word2vec[words[i]].push_back(i);
            } else {
                vector<int> t;
                t.push_back(i);
                word2vec.insert({words[i], t});
            }
        }
        auto v1 = word2vec[word1];
        auto v2 = word2vec[word2];
        int ans = words.size() - 1, i = 0, j = 0;
        while (true) {
            if (v1[i] < v2[j]) {
                ans = min(ans, v2[j] - v1[i]);
                if (i < v1.size() - 1) i++;
                else break;
            } else {
                ans = min(ans, v1[i] - v2[j]);
                if (j < v2.size() - 1) j++;
                else break;
            }
        }
        return ans;
    }
};