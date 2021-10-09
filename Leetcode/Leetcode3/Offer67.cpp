#include <string>

using namespace std;

class Solution {
public:
    int strToInt(string str) {
        long ans = 0;
        bool flag = true;
        int cur = 0;
        for (; cur < str.size(); cur++) {
            if (str[cur] >= '0' && str[cur] <= '9') break;
            else if (str[cur] == '-') { flag = !flag; cur++; break; }
            else if (str[cur] == '+') { cur++; break; }
            else if (str[cur] == ' ') continue;
            else return 0;
        }

        while (cur < str.size()) {
            if (!(str[cur] >= '0' && str[cur] <= '9')) break;
            ans = ans * 10 + str[cur] - '0';
            if (flag && ans > INT32_MAX) return INT32_MAX;
            if (!flag && -ans < INT32_MIN) return INT32_MIN; 
            cur++;
        }

        return flag ? ans : -ans;
    }
};