#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_set<string> us(dictionary.begin(), dictionary.end());
        string ans;
        int left = 0;
        for (int i = 0; i < sentence.size(); i++) {
            string temp = sentence.substr(left, i - left);
            if (i == sentence.size() - 1) {
                ans.append(sentence.substr(left, i - left + 1));
                continue;
            }
            if (sentence[i] == ' ') {
                ans.append(temp);
                if (i != sentence.size() - 1)
                    ans.push_back(' ');
                left = i + 1;
                continue;
            }
            if (us.count(temp)) {
                ans.append(temp);
                while (i < sentence.size() && sentence[i] != ' ')
                    i++;
                if (i != sentence.size())
                    ans.push_back(' ');
                left = i + 1;
            }
        }
        return ans;
    }
};