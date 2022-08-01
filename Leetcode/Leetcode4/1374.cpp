#include <string>

using namespace std;

class Solution {
public:
    string generateTheString(int n) {
        string ans;
        for (int i = 0; i < n - 1; i++)
                ans.push_back('a');
        if (n % 2 == 0)
            ans.push_back('b');
        else
            ans.push_back('a');
        return ans;
    }
};