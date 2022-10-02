#include <vector>

using namespace std;

class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int ans = num1;
        vector<int> b1, b2;
        int n1 = 0, n2 = 0;
        while (num1 != 0) {
            b1.push_back(num1 % 2);
            num1 = num1 / 2;
            if (b1.back() == 1)
                n1++;
        }
        reverse(b1.begin(), b1.end());
        while (num2 != 0) {
            b2.push_back(num2 % 2);
            num2 = num2 / 2;
            if (b2.back() == 1)
                n2++;
        }
        reverse(b2.begin(), b2.end());
        if (n1 == n2) return ans;
        
        vector<int> b(b1.size(), 0);
        for (int i = 0; n2 > 0 && i < b1.size(); i++) {
            if (b1[i] == 0) continue;
            b[i] = 1;
            n2--;
        }
        for (int i = b.size() - 1; n2 > 0 && i >= 0; i--) {
            if (b[i] == 1) continue;
            b[i] = 1;
            n2--;
        }
        ans = 0;
        for (int i = 0; i < n2; i++)
            ans = ans * 2 + 1;
        for (int i = 0; i < b.size(); i++) {
            ans = ans * 2 + b[i];
        }
        return ans;
    }
};