#include <string>

using namespace std;

class Solution {
public:
    string baseNeg2(int n) {
        if (n == 0) return "0";
        string ans;
        while (n != 0) {
            if (n % -2 == 0) {
                n = n / (-2);
                ans.push_back('0');
            }
            else {
                n = (n - 1) / (-2);
                ans.push_back('1');
            }
        }
        for (int i = 0; i <= ans.length() / 2; i++)
            swap(ans[i], ans[ans.length() - i - 1]);
        return ans;
    }
};