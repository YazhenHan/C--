#include <string>

using namespace std;

class Solution {
public:
    string replaceSpace(string s) {
        int count = 0, n = s.size();
        for (auto c : s)
            if (c == ' ')
                count++;
        s.resize(n + count * 2);
        int j = n - 1, i = s.size() - 1;
        while (j >= 0)
            if (s[j] != ' ')
                s[i--] = s[j--];
            else
            {
                s[i--] = '0';
                s[i--] = '2';
                s[i--] = '%';
                j--;
            }
        return s;
    }
};