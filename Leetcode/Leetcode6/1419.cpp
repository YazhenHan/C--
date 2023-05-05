#include <string>

using namespace std;

class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        int c = 0, r = 0, o = 0, a = 0, k = 0, n = 0, ans = INT32_MIN;
        for (int i = 0; i < croakOfFrogs.size(); i++) {
            switch (croakOfFrogs[i])
            {
            case 'c':
                c++;
                n++;
                break;
            case 'r':
                r++;
                if (r > c) return -1;
                break;
            case 'o':
                o++;
                if (o > r) return -1;
                break;
            case 'a':
                a++;
                if (a > o) return -1;
                break;
            default:
                k++;
                if (k > a) return -1;
                n--;
                break;
            }
            ans = max(ans, n);
        }
        if (c != r || r != o || o != a || a != k) return -1;
        return ans;
    }
};