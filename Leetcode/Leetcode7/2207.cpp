#include <string>

using namespace std;

class Solution {
public:
    long long maximumSubsequenceCount(string text, string pattern) {
        long long ans1 = 0, ans2 = 0;
        long long a = 0, b = 0;
        for (int i = 0; i < text.size(); i++) {
            if (text[i] == pattern[0]) a++;
            else if (text[i] == pattern[1]) b++;
        }
        if (pattern[0] == pattern[1]) return a * (a + 1) / 2;
        int temp = b;
        ans1 = b;
        for (int i = 0; i < text.size(); i++) {
            if (text[i] == pattern[0]) {
                ans1 += temp;
            } else if (text[i] == pattern[1]) {
                temp--;
            }
        }
        temp = b + 1, ans2 = 0;
        for (int i = 0; i < text.size(); i++) {
            if (text[i] == pattern[0]) {
                ans2 += temp;
            } else if (text[i] == pattern[1]) {
                temp--;
            }
        }
        return max(ans1, ans2);
    }
};