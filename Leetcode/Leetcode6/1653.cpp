#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int minimumDeletions(string s) {
        int an = 0, bn = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'a')
                an++;
            else
                bn++;
        }
        int i = 0, j = s.size() - 1;
        int ans = 0;
        while (i < j) {
            if (s[i] == 'a') {
                i++;
                an--;
            }
            if (s[j] == 'b') {
                j--;
                bn--;
            }
            if (s[i] == 'b' && s[j] == 'a') {
                if (an < bn) {
                    an--;
                    j--;
                } else {
                    bn--;
                    i++;
                }
                ans++;
            }
        }
        return ans;
    }
};