#include <string>

using namespace std;

class Solution {
public:
    int magicalString(int n) {
        string s = "122";
        int ans = 1;
        for (int i = 2, j = 2; i < n; i++) {
            char t1 = s[i], t2 = s[j];
            for (int k = 0; k < t1 - '0'; k++) {
                s.push_back('1' + '2' - t2);
                j++;
            }
            if (t1 == '1')
                ans++;
        }
        return ans;
    }
};