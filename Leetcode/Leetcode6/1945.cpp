#include <string>

using namespace std;

class Solution {
public:
    int getLucky(string s, int k) {
        int temp = 0, ans = 0;
        for (auto c : s) {
            int temp = c - 96;
            while (temp != 0) {
                ans += temp % 10;
                temp /= 10;
            }
        }
        temp = ans;
        for (int i = 1; i < k; i++) {
            ans = 0;
            while (temp != 0) {
                ans += temp % 10;
                temp /= 10;
            }
            temp = ans;
        }
        return ans;
    }
};