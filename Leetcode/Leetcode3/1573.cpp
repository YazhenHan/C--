#include <string>

using namespace std;

class Solution {
public:
    int numWays(string s) {
        long long total = 0;
        for (auto c : s)
            if (c == '1') total++;
        if (total % 3 != 0) return 0;
        if (total == 0) return ((s.size() - 1) * (s.size() - 2)) / 2 % 1000000007;
        long long tota = total / 3;
        long long left = 0, sum = 0;
        for (left = 0; left < s.size(); left++) {
            if (s[left] == '1') sum++;
            if (sum == tota) break;
        }
        long long right = s.size() - 1;
        sum = 0;
        for (right = s.size() - 1; right >= 0; right--) {
            if (s[right] == '1') sum++;
            if (sum == tota) break;
        }
        for (long long i = left + 1; i < s.size(); i++)
            if (s[i] == '1') {
                left = i - left;
                break;
            }
        for (long long i = right - 1; i >= 0; i--)
            if (s[i] == '1') {
                right = right - i;
                break;
            }
        return (left * right) % 1000000007;
    }
};