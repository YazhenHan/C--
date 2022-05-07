#include <vector>
#include <string>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
private:
    bool isMinus(string str1, string str2) {
        int j = 0;
        for (int i = 0; i < str1.size(); i++) {
            if (str1[i] == str2[i]) continue;
            else j++;
        }
        return j == 1;
    }
public:
    int minMutation(string start, string end, vector<string>& bank) {
        queue<string> c;
        c.push(start);
        for (int i = 0; i < bank.size(); i++) {
            int csize = c.size();
            for (int j = 0; j < csize; j++) {
                if (c.front() == end) return i;
                for (auto b : bank) {
                    if (isMinus(c.front(), b)) {
                        if (b == end) return i + 1;
                        c.push(b);
                    }
                }
                c.pop();
            }
        }
        return -1;
    }
};