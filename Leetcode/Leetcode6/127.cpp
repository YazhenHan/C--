#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
private:
    bool isLegal(const string & beginword, const string & word) {
        int ans = 0;
        for (int i = 0; i < beginword.size(); i++) {
            if (beginword[i] != word[i]) {
                ans++;
                if (ans > 1)
                    return false;
            }
        }
        return ans == 1;
    }
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<int, vector<int>> umv;
        for (int i = 0; i < wordList.size(); i++) {
            for (int j = i + 1; j < wordList.size(); j++) {
                if (isLegal(wordList[i], wordList[j])) {
                    umv[i].emplace_back(j);
                    umv[j].emplace_back(i);
                }
            }
        }

        vector<int> t;
        vector<int> temp(wordList.size(), INT32_MAX);
        for (int i = 0; i < wordList.size(); i++) {
            if (isLegal(beginWord, wordList[i])) {
                t.emplace_back(i);
                temp[i] = 1;
            }
        }

        bool flag = true;
        while (flag) {
            flag = false;
            vector<int> t2;
            for (int i = 0; i < t.size(); i++) {
                for (int j = 0; j < umv[t[i]].size(); j++) {
                    if (temp[umv[t[i]][j]] == INT32_MAX) {
                        temp[umv[t[i]][j]] = temp[t[i]] + 1;
                        flag = true;
                        t2.emplace_back(umv[t[i]][j]);
                    }
                }
            }
            if (flag)
                t = t2;
        }
        for (int i = 0; i < temp.size(); i++) {
            if (wordList[i] == endWord && temp[i] != INT32_MAX)
                return temp[i] + 1;
        }
        return 0;
    }
};