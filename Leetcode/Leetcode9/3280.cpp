#include <string>

using namespace std;

class Solution {
private:
    string sToB(string s) {
        int temp = 0;
        for (auto c : s) {
            temp = temp * 10 + (c - '0');
        }
        string ans;
        while (temp != 0) {
            ans.push_back(temp % 2 + '0');
            temp /= 2;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
public:
    string convertDateToBinary(string date) {
        string ans;
        ans += sToB(date.substr(0, 4));
        ans.push_back('-');
        ans += sToB(date.substr(5, 2));
        ans.push_back('-');
        ans += sToB(date.substr(8, 2));
        return ans;
    }
};