#include <string>

using namespace std;

class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int ans = 0;
        for (int i = 0; i < sentence.size(); i++) {
            if (i == 0 || sentence[i - 1] == ' ') {
                ans++;
                bool flag = true;
                int j = 0;
                for (; j < searchWord.size(); j++) {
                    if (sentence[i + j] != searchWord[j]) {
                        flag = false;
                        break;
                    }
                }
                if (flag)
                    return ans;
                i = i + j;
            }
        }
        return -1;
    }
};