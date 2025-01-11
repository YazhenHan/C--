#include <string>

using namespace std;

class Solution {
public:
    string largestGoodInteger(string num) {
        string ans = "";
        for (int i = 0; i + 2 < num.size(); i++) {
            if (num[i] == num[i + 1] && num[i + 1] == num[i + 2]) {
                if (ans == "" || num[i] > ans[0])
                    ans = num.substr(i, 3);
            }
        }
        return ans;
    }
};